source_group("" FILES nonnumber.h sleef.h sleefsp.c sleefdp.c)
	
add_library(sleef STATIC nonnumber.h sleef.h sleefsp.c sleefdp.c)

set_target_properties(sleef PROPERTIES PUBLIC_HEADER sleef.h)
	
install(TARGETS sleef ARCHIVE DESTINATION "lib" PUBLIC_HEADER DESTINATION "include")
	