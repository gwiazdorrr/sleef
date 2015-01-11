include_directories(${CMAKE_BINARY_DIR})

# traverse both platforms and platform_switches
list(LENGTH platforms len1)
math(EXPR len2 "${len1} - 1")

foreach(val RANGE ${len2})
	
	list(GET platforms ${val} p)
	list(GET platform_switches ${val} switch)
	
	source_group("" FILES "iutsimd.c")
	add_executable(iut${p} "iutsimd.c")
	
	# define ENABLE_<P> and architecture switch
	string(TOUPPER ${p} platform_upper)
	set_target_properties(iut${p} PROPERTIES COMPILE_FLAGS "-DENABLE_${platform_upper} ${switch}")
	
	# link with sleef simd library and math
	target_link_libraries(iut${p} sleef${p} m)
	
endforeach()

source_group("" FILES "tester.c")
add_executable(tester tester.c)
target_link_libraries(tester mpfr m)

source_group("" FILES "testeru1.c")
add_executable(testeru1 testeru1.c)
target_link_libraries(testeru1 mpfr m)

source_group("" FILES "testersp.c")
add_executable(testersp testersp.c)
target_link_libraries(testersp mpfr m)

source_group("" FILES "testerspu1.c")
add_executable(testerspu1 testerspu1.c)
target_link_libraries(testerspu1 mpfr m)