include_directories (
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
#    ${GLIB_INCLUDEDIR}
#    ${GLIB_INCLUDE_DIRS}
    ${GOBJECT_INCLUDEDIR}
    ${GOBJECT_INCLUDE_DIRS}
    ${SNDFILE_INCLUDEDIR}
    ${SNDFILE_INCLUDE_DIRS}
)

unset (HAVE_GETOPT_H CACHE)
check_include_file ( getopt.h HAVE_GETOPT_H )

# adding installed getopt support for Windows 
if ( WIN32 AND NOT HAVE_GETOPT_H )
    # let the user choosing additionnal search path
    set (GETOPT_INCLUDE_PATH "" 
        CACHE FILEPATH "Path of getopt.h" )
    set (CMAKE_REQUIRED_INCLUDES ${CMAKE_REQUIRED_INCLUDES} ${GETOPT_INCLUDE_PATH})
    # force check_include_file to see if getopth.h exits in CMAKE_REQUIRED_INCLUDES
    unset (HAVE_GETOPT_H CACHE)
    check_include_file ( getopt.h HAVE_GETOPT_H )
    if ( HAVE_GETOPT_H )
        include_directories ( ${GETOPT_INCLUDE_PATH} )
    endif( HAVE_GETOPT_H )
endif( WIN32 AND NOT HAVE_GETOPT_H )

link_directories (
#    ${GLIB_LIBDIR}
#    ${GLIB_LIBRARY_DIRS}
    ${GOBJECT_LIBDIR}
    ${GOBJECT_LIBRARY_DIRS}
    ${SNDFILE_LIBDIR}
    ${SNDFILE_LIBRARY_DIRS}
)

if ( HAVE_GETOPT_H )
    add_executable ( riff_dump riff_dump.c )
    add_dependencies( riff_dump libinstpatch )
    target_link_libraries( riff_dump libinstpatch )
endif ( HAVE_GETOPT_H )
