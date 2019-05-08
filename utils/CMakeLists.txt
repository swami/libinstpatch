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
if ( WIN32 )
    #let the user choosing additionnal search path
	set (GETOPT_INCLUDE_PATH "d:\\freesw\\include\\getopt" 
	     CACHE FILEPATH "Path of getopt.h" )
	set (CMAKE_REQUIRED_INCLUDES ${GETOPT_INCLUDE_PATH})
	unset (HAVE_GETOPT_H CACHE)
	check_include_file ( getopt.h HAVE_GETOPT_H )
	if ( HAVE_GETOPT_H )
		include_directories ( ${CMAKE_REQUIRED_INCLUDES} )
	endif( HAVE_GETOPT_H )
endif( WIN32 )

link_directories (
    ${GOBJECT_LIBDIR}
    ${GOBJECT_LIBRARY_DIRS}
    ${SNDFILE_LIBDIR}
    ${SNDFILE_LIBRARY_DIRS}
)
add_executable ( riff_dump riff_dump.c )
add_dependencies( riff_dump libinstpatch )
target_link_libraries( riff_dump libinstpatch )
