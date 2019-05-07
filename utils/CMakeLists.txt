include_directories (
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${GOBJECT_INCLUDEDIR}
    ${GOBJECT_INCLUDE_DIRS}
    ${SNDFILE_INCLUDEDIR}
    ${SNDFILE_INCLUDE_DIRS}
)

#adding installed getopt support for Windows 
if (WIN32)
    pkg_check_modules ( GETOPT getopt )
    if(GETOPT_FOUND)
	    include_directories ( ${GETOPT_INCLUDEDIR} )
    endif(GETOPT_FOUND)
endif(WIN32)

link_directories (
    ${GOBJECT_LIBDIR}
    ${GOBJECT_LIBRARY_DIRS}
    ${SNDFILE_LIBDIR}
    ${SNDFILE_LIBRARY_DIRS}
)
add_executable ( riff_dump riff_dump.c )
add_dependencies( riff_dump libinstpatch )
target_link_libraries( riff_dump libinstpatch )
