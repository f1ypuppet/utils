#pragma once

#include "namespace.h"

#if defined(__linux__)
#   define UTILS_OS_LINUX
#endif

#if (defined(_WIN64) || defined(_WIN32))
#   define UTILS_OS_WINDOWS
#endif

UTILS_BEGIN_NAMESPACE(utils)

#if defined(UTILS_OS_LINUX)
inline constexpr bool with_os_linux = true;
#else
inline constexpr bool with_os_linux = false;
#endif

#if defined(UTILS_OS_WINDOWS)
inline constexpr bool with_os_windows = true;
#else
inline constexpr bool with_os_windows = false;
#endif

UTILS_END_NAMESPACE(utils)
