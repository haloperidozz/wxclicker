cmake_minimum_required(VERSION 3.10)
project(wxclicker VERSION 1.0.0 LANGUAGES CXX)

set(wxBUILD_SHARED OFF)
set(wxBUILD_MONOLITHIC OFF)
add_subdirectory(3rdparty/wxWidgets)

add_subdirectory(src)