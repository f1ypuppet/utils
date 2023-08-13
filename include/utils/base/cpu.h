#pragma once

#include "namespace.h"

#if (defined(_M_IX86) || defined(__i386__))
#   define UTILS_CPU_X86_32
#endif

#if (defined(_M_X64) || defined(__x86_64__))
#   define UTILS_CPU_X86_64
#endif

#if defined(UTILS_CPU_X86_32) || defined(UTILS_CPU_X86_64)
#   define UTILS_CPU_X86
#endif

UTILS_NS_BEGIN

#if defined(UTILS_CPU_X86_32)
inline constexpr bool with_cpu_x86_32 = true;
#else
inline constexpr bool with_cpu_x86_32 = false;
#endif

#if defined(UTILS_CPU_X86_64)
inline constexpr bool with_cpu_x86_64 = true;
#else
inline constexpr bool with_cpu_x86_64 = false;
#endif

#if defined(UTILS_CPU_X86)
inline constexpr bool with_cpu_x86 = true;
#else
inline constexpr bool with_cpu_x86 = false;
#endif

UTILS_NS_END
