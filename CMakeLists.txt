# 
# libInstPatch
#
# Copyright (C) 1999-2014 Element Green <element@elementsofsound.org>
#
# See COPYING license file for distribution details
#

cmake_minimum_required ( VERSION 3.6 )
project ( libInstPatch C )

set ( CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake )

# libInstPatch package name
set ( PACKAGE "libinstpatch" )

# libInstPatch package version
set ( IPATCH_VERSION_MAJOR 1 )
set ( IPATCH_VERSION_MINOR 1 )
set ( IPATCH_VERSION_MICRO 7 )
set ( VERSION "${IPATCH_VERSION_MAJOR}.${IPATCH_VERSION_MINOR}.${IPATCH_VERSION_MICRO}" )
set ( IPATCH_VERSION "\"${VERSION}\"" )

# libinstpatch - Library version
# *** NOTICE ***
# Update library version upon each release (follow these steps in order)
# if any source code changes: REVISION++
# if any interfaces added/removed/changed: REVISION=0
# if any interfaces removed/changed (compatibility broken): CURRENT++
# if any interfaces have been added: AGE++
# if any interfaces have been removed/changed (compatibility broken): AGE=0
# This is not exactly the same algorithm as the libtool one, but the results are the same.
set ( LIB_VERSION_CURRENT 2 )
set ( LIB_VERSION_AGE 2 )
set ( LIB_VERSION_REVISION 1 )
set ( LIB_VERSION_INFO 
      "${LIB_VERSION_CURRENT}.${LIB_VERSION_AGE}.${LIB_VERSION_REVISION}" )

# Options disabled by default
option ( enable-debug "enable debugging (default=no)" off )
option ( GTKDOC_ENABLED "Create Gtk-Doc API reference (default=no)" off )
option ( INTROSPECTION_ENABLED "Create GObject Introspection typelib" off )

# Options enabled by default
option ( BUILD_SHARED_LIBS "Build a shared object or DLL" on )

# Initialize the library directory name suffix.
if ( CMAKE_SIZEOF_VOID_P EQUAL 8 )
  set ( _init_lib_suffix "64" )
else ( CMAKE_SIZEOF_VOID_P EQUAL 8 )
  set ( _init_lib_suffix "" )
endif ( CMAKE_SIZEOF_VOID_P EQUAL 8 )

# Sane defaults for CMAKE_INSTALL_*
include ( GNUInstallDirs )

# Default install directory names
include ( DefaultDirs )

# Basic C library checks
include ( CheckCCompilerFlag )
include ( CheckSTDC )
include ( CheckIncludeFile )
check_include_file ( string.h HAVE_STRING_H )
check_include_file ( stdlib.h HAVE_STDLIB_H )
check_include_file ( stdio.h HAVE_STDIO_H )
check_include_file ( math.h HAVE_MATH_H )
check_include_file ( errno.h HAVE_ERRNO_H )
check_include_file ( stdarg.h HAVE_STDARG_H )
check_include_file ( unistd.h HAVE_UNISTD_H )
check_include_file ( locale.h HAVE_LOCALE_H )
check_include_file ( xlocale.h HAVE_XLOCALE_H )

if ( WIN32 )
  # Check presence of MS include files
  check_include_file ( io.h HAVE_IO_H )
endif( WIN32 )


unset ( IPATCH_CPPFLAGS CACHE )
unset ( IPATCH_LIBS CACHE )

# Options for the GNU C compiler only
if ( CMAKE_COMPILER_IS_GNUCC )
  if ( NOT APPLE )
    set ( CMAKE_EXE_LINKER_FLAGS 
          "${CMAKE_EXE_LINKER_FLAGS} -Wl,--as-needed" )
    set ( CMAKE_SHARED_LINKER_FLAGS 
          "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined" )
  endif ( NOT APPLE )
  set ( GNUCC_WARNING_FLAGS "-Wall")
  set ( CMAKE_C_FLAGS "-pedantic ${CMAKE_C_FLAGS}" )
  set ( CMAKE_C_FLAGS_DEBUG "-g -DDEBUG -fsanitize=undefined ${GNUCC_WARNING_FLAGS} ${CMAKE_C_FLAGS_DEBUG}" )
  set ( CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG ${GNUCC_WARNING_FLAGS} ${CMAKE_C_FLAGS_RELEASE}" )
  set ( CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g -DNDEBUG ${GNUCC_WARNING_FLAGS} ${CMAKE_C_FLAGS_RELWITHDEBINFO}" )
endif ( CMAKE_COMPILER_IS_GNUCC )

if ( MSVC )
    # statically link in the CRT library to avoid a bunch of runtime DLL dependencies and allow 
    # the CI windows builds to be run under WinXP
    foreach ( flag_var
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        CMAKE_C_FLAGS_MINSIZEREL
        CMAKE_C_FLAGS_RELWITHDEBINFO
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL
        CMAKE_CXX_FLAGS_RELWITHDEBINFO
        )
      if ( ${flag_var} MATCHES "/MD" )
        string ( REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}" )
      endif ( ${flag_var} MATCHES "/MD" )
    endforeach ( flag_var )
endif ( MSVC )

if ( enable-debug )  
    set ( CMAKE_BUILD_TYPE "Debug" CACHE STRING
          "Choose the build type, options: Debug Release RelWithDebInfo" FORCE )
    set ( IPATCH_DEBUG 1 )
endif ( enable-debug )

unset ( MINGW32 CACHE )
if ( WIN32 )
  # MinGW compiler (a Windows GCC port)
  if ( MINGW ) 
    set ( MINGW32 1 )
    # Check if -mms-bitfields is supported (ARM64 does not)
    check_c_compiler_flag( "-mms-bitfields" COMPILER_SUPPORTS_MMS_BITFIELDS )
    if ( COMPILER_SUPPORTS_MMS_BITFIELDS )
      add_definitions ( -mms-bitfields )
    endif ()
  endif  ( MINGW )
else ( WIN32 )
  set ( IPATCH_LIBS "m" )
endif ( WIN32 )

unset ( ENABLE_DEBUG CACHE )
unset ( DEBUG CACHE )
if ( CMAKE_BUILD_TYPE MATCHES "Debug" )
    set ( ENABLE_DEBUG 1 )
    set ( DEBUG 1 )
endif ( CMAKE_BUILD_TYPE MATCHES "Debug" )

# Mandatory tool: pkg-config
find_package ( PkgConfig REQUIRED )

# Mandatory libraries: gobject, glib and gthread
pkg_check_modules ( GOBJECT REQUIRED gobject-2.0>=2.12 glib-2.0>=2.12 gthread-2.0>=2.12 )

# Disable deprecation warnings for now (fixed in master)
add_definitions ( -DGLIB_DISABLE_DEPRECATION_WARNINGS )

include ( UnsetPkgConfig )

# Check for libsndfile
find_package ( SndFile 1.2.1 )
if ( NOT SNDFILE_FOUND )
  pkg_check_modules ( SNDFILE REQUIRED sndfile>=1.2.1 )
endif()

# Check for GObjectIntrospection binding
if (INTROSPECTION_ENABLED)
  include (FindGObjectIntrospection)
endif ()

# Check for Gtk-Doc
if (GTKDOC_ENABLED)
  find_package(GtkDoc)
endif ()

# General configuration file
configure_file ( ${CMAKE_SOURCE_DIR}/config.h.cmake 
                 ${CMAKE_BINARY_DIR}/config.h )
add_definitions ( -DHAVE_CONFIG_H )

# Version and master libinstpatch.h file
configure_file ( ${CMAKE_SOURCE_DIR}/libinstpatch/version.h.in
                 ${CMAKE_CURRENT_BINARY_DIR}/libinstpatch/version.h )
configure_file ( ${CMAKE_SOURCE_DIR}/libinstpatch/libinstpatch.h.in
                 ${CMAKE_CURRENT_BINARY_DIR}/libinstpatch/libinstpatch.h )

set (INSTPATCH_INSTALL_TARGET "libinstpatch-${LIB_VERSION_CURRENT}")

# pkg-config support
if ( UNIX OR MINGW OR WIN32)
    # stamp library name with version current value (for Windows only)
    if(MINGW OR WIN32)
        set ( lib_version_suffix ${LIB_VERSION_CURRENT} )
    else(MINGW OR WIN32)
        set ( lib_version_suffix 1.0 )
    endif(MINGW OR WIN32)
    configure_file ( libinstpatch-1.0.pc.in
        ${CMAKE_BINARY_DIR}/libinstpatch-1.0.pc IMMEDIATE @ONLY )
    install ( FILES ${CMAKE_BINARY_DIR}/libinstpatch-1.0.pc
              DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig )
endif ( UNIX OR MINGW OR WIN32)

# Extra targets for Unix build environments
if ( UNIX )
    # uninstall custom target
    configure_file ( "${CMAKE_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
      "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake" IMMEDIATE @ONLY)
    add_custom_target ( uninstall
      "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")
endif ( UNIX )

# Process subdirectories 
add_subdirectory ( libinstpatch )
add_subdirectory ( utils )
add_subdirectory ( docs )

# CPack support 
set ( CPACK_PACKAGE_DESCRIPTION_SUMMARY "libInstPatch instrument editing library" )
set ( CPACK_PACKAGE_VENDOR "swami.sourceforge.net" )
set ( CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_SOURCE_DIR}/README.md" )
set ( CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING" )
set ( CPACK_PACKAGE_VERSION_MAJOR ${IPATCH_VERSION_MAJOR} )
set ( CPACK_PACKAGE_VERSION_MINOR ${IPATCH_VERSION_MINOR} )
set ( CPACK_PACKAGE_VERSION_PATCH ${IPATCH_VERSION_MICRO} )

# source packages
set ( CPACK_SOURCE_GENERATOR TGZ;TBZ2;ZIP )
set ( CPACK_SOURCE_IGNORE_FILES "/.svn/;~$;.cproject;.project;/.settings/;${CPACK_SOURCE_IGNORE_FILES}" )
set ( CPACK_SOURCE_PACKAGE_FILE_NAME "${PACKAGE}-${VERSION}" ) 
set ( CPACK_SOURCE_STRIP_FILES OFF )

# binary packages
include ( InstallRequiredSystemLibraries )
set ( CPACK_GENERATOR STGZ;TGZ;TBZ2;ZIP )
set ( CPACK_PACKAGE_NAME ${PACKAGE} )
set ( CPACK_STRIP_FILES ON )

include ( CPack )

message ( "Build options:" )

if ( ENABLE_DEBUG )
  message ( "Debug:                 yes" )
else ( ENABLE_DEBUG )
  message ( "Debug:                 no" )
endif ( ENABLE_DEBUG )

if (INTROSPECTION_FOUND)
  message ( "GObjectIntrospection:  yes" ) 
else (INTROSPECTION_FOUND)
  message ( "GObjectIntrospection:  no" ) 
endif(INTROSPECTION_FOUND)

if (GTKDOC_FOUND)
  message ( "Gtk-Doc API reference: yes" ) 
else (GTKDOC_FOUND)
  message ( "Gtk-Doc API reference: no" ) 
endif(GTKDOC_FOUND)

file(GLOB_RECURSE
     ALL_SOURCE_FILES
     LIST_DIRECTORIES false
     ${CMAKE_SOURCE_DIR}/*.[chi]
     ${CMAKE_SOURCE_DIR}/*.[chi]pp
     ${CMAKE_SOURCE_DIR}/*.[chi]xx
     ${CMAKE_SOURCE_DIR}/*.cc
     ${CMAKE_SOURCE_DIR}/*.hh
     ${CMAKE_SOURCE_DIR}/*.ii
     ${CMAKE_SOURCE_DIR}/*.[CHI]
     )
     
find_program ( ASTYLE "astyle" )
if ( ASTYLE )
  add_custom_target(
    format
    COMMAND ${ASTYLE}
    -A1
    -xb
    -j
    -k3
    -p
    -f
    -n
    -U
    ${ALL_SOURCE_FILES}
    )
endif ( ASTYLE)
