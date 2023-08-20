#pragma once

#define UTILS_CLASS_NO_COPY(cls)\
    cls(const cls&) = delete;\
    cls& operator=(const cls&) = delete

#define UTILS_CLASS_NO_MOVE(cls)\
    cls(cls&&) noexcept = delete;\
    cls& operator=(cls&&) noexcept = delete
