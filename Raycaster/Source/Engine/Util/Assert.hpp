#pragma once

#include <windows.h>

#define ASSERT(expr) \
	if (expr) {} \
	else {\
		__debugbreak();\
	}