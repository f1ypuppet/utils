#pragma once

#include "namespace.h"

#if defined(__clang__)
#   define UTILS_COMPILER_CLANG
#endif

#if defined(__GNUC__) && !defined(__clang__)
#   define UTILS_COMPILER_GCC
#endif

#if defined(_MSC_VER)
#   define UTILS_COMPILER_MSC
#endif

UTILS_NS_BEGIN

#if defined(UTILS_COMPILER_CLANG)
inline constexpr bool with_compiler_clang = true;
#else
inline constexpr bool with_compiler_clang = false;
#endif

#if defined(UTILS_COMPILER_GCC)
inline constexpr bool with_compiler_gcc = true;
#else
inline constexpr bool with_compiler_gcc = false;
#endif

#if defined(UTILS_COMPILER_MSC)
inline constexpr bool with_compiler_msc = true;
#else
inline constexpr bool with_compiler_msc = false;
#endif

UTILS_NS_END
