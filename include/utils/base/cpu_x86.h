#pragma once

#include <bitset>
#include <string_view>

#include "class.h"
#include "namespace.h"

UTILS_BEGIN_NAMESPACE(utils)
UTILS_BEGIN_NAMESPACE(cpu_x86)

enum class cpu_x86_feature_bias : size_t {
    init        = 0UL,

    lzcnt       = 1UL,
    popcnt      = 2UL,
    sse2        = 3UL,
    sse4        = 4UL,
    avx1        = 5UL,
    avx2        = 6UL,
    avx512f     = 7UL,
    avx512vl    = 8UL,
    avx512bw    = 9UL,
    avx512dq    = 10UL,
    avx512vbmi2 = 11UL,

    total       = 12UL,
};

class cpu_x86_features final {
private:
    using feature_bias = cpu_x86_feature_bias;
    using storage_type = std::bitset<static_cast<size_t>(feature_bias::total)>;

public:
    UTILS_CLASS_NO_COPY(cpu_x86_features);

    static constexpr std::string_view arch_name() noexcept {
        using std::literals::string_view_literals::operator ""sv;
        return "x86"sv;
    }

    bool is_inited() const noexcept {
        return features_[static_cast<size_t>(feature_bias::init)];
    }

#define UTILS_APPLY_FEATURE(f)\
    bool enable_##f() const noexcept {\
        return features_[static_cast<size_t>(feature_bias::f)];\
    }

    UTILS_APPLY_FEATURE(lzcnt)
    UTILS_APPLY_FEATURE(popcnt)
    UTILS_APPLY_FEATURE(sse2)
    UTILS_APPLY_FEATURE(sse4)
    UTILS_APPLY_FEATURE(avx1)
    UTILS_APPLY_FEATURE(avx2)
    UTILS_APPLY_FEATURE(avx512f)
    UTILS_APPLY_FEATURE(avx512vl)
    UTILS_APPLY_FEATURE(avx512bw)
    UTILS_APPLY_FEATURE(avx512dq)
    UTILS_APPLY_FEATURE(avx512vbmi2)

#undef UTILS_APPLY_FEATURE

private:
    friend cpu_x86_features& get_cpu_x86_features();

    cpu_x86_features() noexcept = default;

private:
    storage_type features_;
};

UTILS_END_NAMESPACE(cpu_x86)

using cpu_x86_features = cpu_x86::cpu_x86_features;

cpu_x86_features& get_cpu_x86_features();

UTILS_END_NAMESPACE(utils)
