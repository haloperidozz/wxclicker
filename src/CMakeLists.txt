find_package(X11 COMPONENTS Xtst)

add_executable(wxclicker)

target_compile_features(wxclicker PRIVATE cxx_std_20)

target_include_directories(wxclicker PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(wxclicker PRIVATE
    application/ClickerApplication.cxx
    mouse/MouseInputBackendRegistry.cxx
    mouse/RegisterPlatformBackends.cxx
    services/AutoClicker.cxx
    ui/generated/BaseClickerFrame.cpp
    ui/PickScreenPointDialog.cxx
    ui/ClickerFrame.cxx
)

if (WIN32)
    target_compile_definitions(wxclicker PRIVATE WXCLICKER_WIN32)
    target_sources(wxclicker PRIVATE
        mouse/win32/BaseMouseInputBackend.cxx
        mouse/win32/NtUserSendInputBackend.cxx
        mouse/win32/SendInputBackend.cxx
        resource/WxClicker.rc
    )
elseif (UNIX AND NOT APPLE)
    target_compile_definitions(wxclicker PRIVATE WXCLICKER_LINUX)
else ()
    message(FATAL_ERROR "${CMAKE_SYSTEM_NAME} not supported")
endif ()

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/buildinfo/BuildInfo.hxx.in
    ${CMAKE_CURRENT_SOURCE_DIR}/buildinfo/BuildInfo.hxx
    @ONLY
)

if (MINGW AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_link_options(wxclicker PRIVATE
        $<$<CONFIG:Release>:-s>
        -static-libgcc
        -static-libstdc++
        -static
    )
endif ()

if(WIN32)
    set_target_properties(wxclicker PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
endif()

target_link_libraries(wxclicker PRIVATE wx::core wx::base)

if (X11_FOUND)
    target_compile_definitions(wxclicker PRIVATE WXCLICKER_X11)
    target_link_libraries(wxclicker PRIVATE X11::X11 X11::Xtst)
    target_sources(wxclicker PRIVATE
        mouse/x11/XTestMouseInputBackend.cxx
    )
endif ()
