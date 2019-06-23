##---------------------------------------------------------------------------
## Author:      Egil Kvaleberg
## Copyright:   
## License:     wxWidgets License
##---------------------------------------------------------------------------

# define minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.2)

PROJECT(vmg_pi)

SET(PACKAGE_NAME vmg_pi)
SET(VERBOSE_NAME VMG)
SET(TITLE_NAME VMG)
SET(CPACK_PACKAGE_CONTACT "Egil Kvaleberg")

SET(NAME_SUFFIX "ov50")

SET(VERSION_MAJOR "0")
SET(VERSION_MINOR "1")

#SET(CMAKE_BUILD_TYPE Debug)

SET(CMAKE_MACOSX_RPATH "ON")

set (CMAKE_CXX_STANDARD 11)

OPTION(VMG_USE_SVG "Use SVG graphics" OFF)

INCLUDE("cmake/PluginConfigure.cmake")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s")

IF(VMG_USE_SVG)
  ADD_DEFINITIONS(-DVMG_USE_SVG)
ENDIF(VMG_USE_SVG)

SET(SRC_VMG
	    src/vmg_pi.h
	    src/vmg_pi.cpp
            src/icons.h
            src/icons.cpp
	    src/vmggui.h
	    src/vmggui.cpp
	    src/vmggui_impl.cpp
	    src/vmggui_impl.h
        )

ADD_LIBRARY(${PACKAGE_NAME} SHARED ${SRC_VMG})

INCLUDE("cmake/PluginInstall.cmake")
INCLUDE("cmake/PluginLocalization.cmake")
INCLUDE("cmake/PluginPackage.cmake")
