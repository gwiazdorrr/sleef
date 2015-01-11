function(cat IN_FILE OUT_FILE)
  file(READ ${IN_FILE} CONTENTS)
  file(APPEND ${OUT_FILE} "${CONTENTS}")
endfunction()

include_directories(${CMAKE_BINARY_DIR})

set(common_headers "df.h" "dd.h" "nonnumber.h")
set(common_src "sleefsimddp.c" "sleefsimdsp.c")	
source_group("" FILES ${common_headers} ${common_src})

# traverse both platforms and platform_switches
list(LENGTH platforms len1)
math(EXPR len2 "${len1} - 1")

foreach(val RANGE ${len2})
	
	list(GET platforms ${val} p)
	list(GET platform_switches ${val} switch)
	
	# generate platform header
	set(temp_file "${CMAKE_BINARY_DIR}/sleef${p}.h.temp")
	
	file(WRITE ${temp_file} "")
	cat("sleef${p}.partial.h" ${temp_file})
	file(APPEND ${temp_file} "\n")
	cat("sleefsimdsp.partial.h" ${temp_file})
	file(APPEND ${temp_file} "\n")
	cat("sleefsimddp.partial.h" ${temp_file})
	
	set(target_file "${CMAKE_BINARY_DIR}/sleef${p}.h")
	configure_file(${temp_file} ${target_file} COPYONLY)
	
	set(platform_headers "helper${p}.h" "sleef${p}.partial.h")
	source_group("" FILES ${platform_headers})
	source_group("generated" FILES ${target_file})
	
	set(partial_headers sleef${p}.partial.h sleefsimdsp.partial.h sleefsimddp.partial.h)
	source_group("partial" FILES ${partial_headers})
	
	add_library(sleef${p} STATIC ${target_file} ${common_headers} ${common_src} ${platform_headers} ${partial_headers})
	
	# define ENABLE_<P> and architecture switch
	string(TOUPPER ${p} platform_upper)
	
	set_target_properties(sleef${p} PROPERTIES COMPILE_FLAGS "-DENABLE_${platform_upper} ${switch}")
	set_target_properties(sleef${p} PROPERTIES PUBLIC_HEADER ${target_file})
	
	install(TARGETS sleef${p} ARCHIVE DESTINATION "lib" PUBLIC_HEADER DESTINATION "include")
	
endforeach()