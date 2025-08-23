/*
 * Copyright (C) 2025 haloperidozz
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "services/AutoClicker.hxx"

namespace wxclicker::services {

AutoClicker::AutoClicker(const Options& options)
    : _options{options}
{
}

void AutoClicker::WorkerThread(std::stop_token stopToken, mouse::MouseBackendPtr pBackend)
{
    Options options;

    {
        std::scoped_lock lock{_mutex};
        options = _options;
    }

    std::unique_lock<std::mutex> cvLock{_cvMutex};

    auto delay = [&](auto duration) {
        _cv.wait_for(cvLock, duration, [&stopToken] {
            return stopToken.stop_requested();
        });
    };

    std::size_t counter{0};

    while (!stopToken.stop_requested()) {
        if (options.repeatTimes && counter >= *options.repeatTimes) {
            break;
        }

        if (options.clickPosition) {
            const auto[x, y] = *options.clickPosition;

            pBackend->SetPosition(x, y);
        }

        for (int i{0}; i < options.clickCount; ++i) {
            pBackend->Down(options.button);
            delay(options.clickDelay);
            pBackend->Up(options.button);
        }

        delay(options.interval);
                
        if (options.repeatTimes) {
            ++counter;
        }
    }

    OnFinishedCallback onFinished;

    {
        std::scoped_lock lock{_mutex};
        onFinished = _onFinished;
    }

    if (onFinished) {
        onFinished();
    }
}

void AutoClicker::Start(mouse::MouseBackendPtr pBackend)
{
    using namespace std::placeholders;

    if (!pBackend) {
        throw std::invalid_argument{"pBackend is null"};
    }

    std::scoped_lock lock{_mutex};

    if (_workerThread.joinable()) {
        _workerThread.request_stop();
        _cv.notify_all();
        _workerThread.join();
    }

    // signature:
    // WorkerThread(AutoClicker*, std::stop_token, MouseBackendPtr)
    _workerThread = std::jthread{
        std::bind(&AutoClicker::WorkerThread, this, _1, pBackend)
    };
}

void AutoClicker::RequestStop() noexcept
{
    std::scoped_lock lock{_mutex};

    if (_workerThread.joinable()) {
        _workerThread.request_stop();
        _cv.notify_all();
    }
}

void AutoClicker::OnFinished(OnFinishedCallback callback)
{
    std::scoped_lock lock{_mutex};

    _onFinished = std::move(callback);
}

void AutoClicker::Configure(const Options& options)
{
    std::scoped_lock lock{_mutex};

    _options = options;
}

} // namespace wxclicker::services
