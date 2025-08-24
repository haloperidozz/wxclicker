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

#pragma once

#include <thread>
#include <memory>
#include <mutex>
#include <functional>
#include <optional>
#include <condition_variable>
#include <chrono>
#include <utility>

#include "mouse/IMouseInputBackend.hxx"
#include "mouse/MouseButton.hxx"

namespace wxclicker::services {

class AutoClicker final
{
public:
    using OnFinishedCallback = std::function<void()>;

    struct Options
    {
        mouse::MouseButton button{mouse::MouseButton::Left};
        std::chrono::milliseconds interval{100};
        std::chrono::milliseconds clickDelay{0};
        std::optional<int> repeatTimes{};
        int clickCount{1};
        std::optional<std::pair<int, int>> clickPosition{};
    };

    explicit AutoClicker() = default;
    explicit AutoClicker(const Options& options);

    AutoClicker(const AutoClicker&) = delete;
    AutoClicker& operator=(const AutoClicker&) = delete;

    AutoClicker(AutoClicker&&) noexcept = delete;
    AutoClicker& operator=(AutoClicker&&) noexcept = delete;

    void Start(mouse::MouseInputBackendShared backend);
    void RequestStop() noexcept;

    void OnFinished(OnFinishedCallback callback);
    
    void Configure(const Options& options);

private:
    void WorkerThread(
        std::stop_token stopToken,
        mouse::MouseInputBackendShared backend);

    Options                             _options{};
    OnFinishedCallback                  _onFinished;

    std::jthread                        _workerThread;
    mutable std::mutex                  _mutex;
    mutable std::mutex                  _cvMutex;
    mutable std::condition_variable_any _cv;
};

} // namespace wxclicker::services
