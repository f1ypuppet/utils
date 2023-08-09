include(CheckCSourceCompiles)

set(UTILS_HAVE_CPUID_H OFF CACHE BOOL "...")
check_c_source_compiles("
  #include <cpuid.h>
  int main(void) {
    unsigned a, b, c, d;
    unsigned max = __get_cpuid_max(0, 0);
  
    if (max >= 1) {
        __cpuid(1, a, b, c, d);
    }
  
    if (max >= 7) {
        __cpuid_count(7, 0, a, b, c, d);
    }
  
    return 0;
  }"
  _HAVE_CPUID_H
)

if(_HAVE_CPUID_H)
    set(UTILS_HAVE_CPUID_H ON CACHE BOOL "..." FORCE)
elseif(UTILS_HAVE_CPUID_H)
    message(WARNING "<cpuid.h> not found")
    set(UTILS_HAVE_CPUID_H OFF CACHE BOOL "..." FORCE)
endif()
unset(_HAVE_CPUID_H)

message(NOTICE "`UTILS_HAVE_CPUID_H` is set to `${UTILS_HAVE_CPUID_H}`")