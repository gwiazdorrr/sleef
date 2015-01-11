cmake_minimum_required(VERSION 2.6)
project (sleef LANGUAGES C)

if(MSVC)
	set(platforms sse2 avx avx2)
	set(platform_switches "" "/arch:AVX" "/arch:AVX2" )
elseif (CMAKE_C_COMPILER_ID STREQUAL "Intel")
	# https://software.intel.com/sites/products/documentation/doclib/iss/2013/compiler/cpp-lin/GUID-B4670EED-D317-46D4-9635-618B36C827C3.htm
	set(platforms sse2 avx avx2)
	set(platform_switches "-msse2" "-mavx" "-march=core-avx2" )
else()
	# based on the original Makefile
	set(platforms sse2 avx avx2 fma4)
	set(platform_switches "-msse2" "-mavx" "-mavx2 -mfma" "-mavx -mfma4" )
endif()

# NOTE: arm neon used these switches: -mfloat-abi=softfp -mfpu=neon -static

add_subdirectory(simd)

set(BUILD_TESTS OFF CACHE BOOL "Requires Unix-like environment")

if(BUILD_TESTS)
	add_subdirectory(tester)
endif()