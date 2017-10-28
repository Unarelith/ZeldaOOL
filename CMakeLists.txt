#------------------------------------------------------------------------------
# CMakeLists.txt
# By gnidmoo <gnidmoo@gmail.com>
#------------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.8)

project(ZeldaOOL)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

#------------------------------------------------------------------------------
# Get source files
#------------------------------------------------------------------------------
file(GLOB_RECURSE SOURCE_FILES source/*/*.cpp external/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.hpp external/*.hpp)

foreach(HEADER_FILE ${HEADER_FILES})
	get_filename_component(HEADER_DIRECTORY ${HEADER_FILE} DIRECTORY)
	include_directories(${HEADER_DIRECTORY})
endforeach(HEADER_FILE)

#------------------------------------------------------------------------------
# Unit testing
#------------------------------------------------------------------------------
find_package(CxxTest QUIET)

if(CXXTEST_FOUND)
	include_directories(${CXXTEST_INCLUDE_DIRS})
	enable_testing()

	file(GLOB_RECURSE TEST_FILES tests/*.hpp)

	CXXTEST_ADD_TEST(${CMAKE_PROJECT_NAME}_tests tests/unit-test.cpp ${TEST_FILES})
else(CXXTEST_FOUND)
	message(WARNING "CxxTest not found!")
endif(CXXTEST_FOUND)

#------------------------------------------------------------------------------
# Add executables
#------------------------------------------------------------------------------
add_library(${CMAKE_PROJECT_NAME}_lib STATIC
            ${SOURCE_FILES})

add_executable(${CMAKE_PROJECT_NAME}
               source/main.cpp)

#------------------------------------------------------------------------------
# Compiler flags
#------------------------------------------------------------------------------
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wfatal-errors")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-variadic-macros")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
endif()

#------------------------------------------------------------------------------
# Packages
#------------------------------------------------------------------------------
# - tinyxml2
#------------------------------------------------------------------------------
find_package(TinyXml2 REQUIRED)
if(NOT TINYXML2_FOUND)
	message(FATAL_ERROR "tinyxml2 is needed to build the project. Please install it correctly.")
endif()

include_directories(${TINYXML2_INCLUDE_DIRS})
link_directories(${TINYXML2_LIBRARY_DIRS})

#------------------------------------------------------------------------------
# - OpenGL
#------------------------------------------------------------------------------
find_package(OpenGL REQUIRED)
find_package(GLM REQUIRED)

if(NOT OPENGL_FOUND)
	message(FATAL_ERROR "OpenGL not found!")
endif(NOT OPENGL_FOUND)

if(NOT GLM_FOUND)
	message(FATAL_ERROR "glm not found!")
endif(NOT GLM_FOUND)

include_directories(${GLM_INCLUDE_DIRS})

#------------------------------------------------------------------------------
# - SDL2, SDL2_image, SDL2_mixer
#------------------------------------------------------------------------------
include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer)

if(NOT SDL2_FOUND)
	message(FATAL_ERROR "SDL2 not found!")
endif(NOT SDL2_FOUND)

if(NOT SDL2IMAGE_FOUND)
	message(FATAL_ERROR "SDL2_image not found!")
endif(NOT SDL2IMAGE_FOUND)

if(NOT SDL2MIXER_FOUND)
	message(FATAL_ERROR "SDL2_mixer not found!")
endif(NOT SDL2MIXER_FOUND)

include_directories(${SDL2_INCLUDE_DIRS}
                    ${SDL2IMAGE_INCLUDE_DIRS}
                    ${SDL2MIXER_INCLUDE_DIRS})

#------------------------------------------------------------------------------
# Link options
#------------------------------------------------------------------------------
if(CXXTEST_FOUND)
	target_link_libraries(${CMAKE_PROJECT_NAME}_tests
	                      ${CMAKE_PROJECT_NAME}_lib
	                      ${TINYXML2_LIBRARIES}
	                      ${OPENGL_LIBRARIES}
	                      ${SDL2_LIBRARIES}
	                      ${SDL2IMAGE_LIBRARIES}
	                      ${SDL2MIXER_LIBRARIES})
endif(CXXTEST_FOUND)

target_link_libraries(${CMAKE_PROJECT_NAME}
                      ${CMAKE_PROJECT_NAME}_lib
                      ${TINYXML2_LIBRARIES}
                      ${OPENGL_LIBRARIES}
                      ${SDL2_LIBRARIES}
                      ${SDL2IMAGE_LIBRARIES}
                      ${SDL2MIXER_LIBRARIES})

