#pragma once

#include <windows.h>
#include "Application.hpp"

#define PLATFORM_WINDOWS

core::Application* CreateApplication();

#ifdef PLATFORM_WINDOWS
#include "../../../Platform/Windows/Public/WindowsEntryPoint.hpp"
#endif