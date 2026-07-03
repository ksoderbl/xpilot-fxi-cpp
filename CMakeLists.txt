cmake_minimum_required(VERSION 3.16)

project(xpilot-fxi-cpp VERSION 1.4.6 LANGUAGES C CXX)

include(GNUInstallDirs)
include(CheckFunctionExists)

option(XPILOT_ENABLE_PLOCKSERVER "Lock the server into memory" OFF)
option(XPILOT_ENABLE_DEVELOPMENT "Enable development code" OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(PACKAGE "xpilot-fxi-cpp")
set(PACKAGE_NAME "XPilot FXI CPP")
set(PACKAGE_TARNAME "xpilot-fxi-cpp")
set(PACKAGE_VERSION "1.4.6fxi")
set(PACKAGE_STRING "XPilot FXI CPP 1.4.6fxi")
set(PACKAGE_BUGREPORT "https://github.com/ksoderbl/xpilot-fxi-cpp")
set(PACKAGE_URL "https://github.com/ksoderbl/xpilot-fxi-cpp")
set(VERSION "1.4.6fxi")

set(XP_AUTHORS "Bjoern Stabell, Ken Ronny Schouten, Bert Gijsbers, Dick Balaska, Kristian Soderblom, et al")
set(XP_COPYRIGHTDATE "1991-2025")
set(XP_COPYRIGHT "Copyright (C) ${XP_COPYRIGHTDATE} by ${XP_AUTHORS}")
set(XP_RELEASEDATE "Apr 1, 2009")

# Install data in the same style as the autotools build:
#   $(pkgdatadir) == ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME}
set(XPILOT_PKGDATADIR "${CMAKE_INSTALL_FULL_DATADIR}/${PROJECT_NAME}")
set(XPILOT_CONF_DATADIR "${XPILOT_PKGDATADIR}/")

check_function_exists(strlcpy HAVE_STRLCPY)
check_function_exists(strlcat HAVE_STRLCAT)
check_function_exists(strcasecmp HAVE_STRCASECMP)
check_function_exists(strncasecmp HAVE_STRNCASECMP)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/generated/config.h
    @ONLY
)

find_package(PkgConfig REQUIRED)
find_package(ZLIB REQUIRED)
find_package(EXPAT REQUIRED)


# add_compile_options(
#     -Wall
#     -Wextra
#     -Wpedantic
#     -Wformat=2
#     -Wundef
#     -Wshadow
#     -Wcast-qual
#     -Wwrite-strings
#     -Wredundant-decls
#     -Wmissing-declarations
#     -Woverloaded-virtual
#     -Wnon-virtual-dtor
#     -Wold-style-cast
#     -Wzero-as-null-pointer-constant
#     -Wuseless-cast
# )

add_compile_options(
    # -Wall
    # -Wextra
    # -Wformat=2
    # -Wundef
    # -Wshadow
    # -Wpointer-arith
    # -Wcast-qual
    # -Wwrite-strings
    # -Wmissing-declarations
    # -Wuninitialized
    # -Winit-self
    # -Wno-unused-parameter
)

# Later we need only:
# -Wconversion
# -Wsign-conversion
# -Wnull-dereference

add_subdirectory(src)

# Runtime data files from lib/Makefile.am
install(
    FILES
        lib/defaults.txt
        lib/password.txt
        lib/robots.txt
        lib/shipshapes.txt
    DESTINATION ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME}
)

install(
    DIRECTORY
        lib/fonts
        lib/maps
        lib/textures
    DESTINATION ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME}
)
