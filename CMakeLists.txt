#------------------------------------------------------------------------------
# CMakeLists.txt
# By gnidmoo <gnidmoo@gmail.com>
#------------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.8)

project(ZeldaOOL)

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
file(GLOB_RECURSE TESTS_FILES tests/*.hpp)

find_package(CxxTest REQUIRED)

if(NOT CXXTEST_FOUND)
	message(FATAL_ERROR "CxxTest not found !")
endif(NOT CXXTEST_FOUND)

include_directories(${CXXTEST_INCLUDE_DIRS})

ENABLE_TESTING()
CXXTEST_ADD_TEST(unit-test tests/unit-test.cpp ${TESTS_FILES})

#------------------------------------------------------------------------------
# Add executables
#------------------------------------------------------------------------------
add_library(${CMAKE_PROJECT_NAME}_lib STATIC
            ${SOURCE_FILES})

add_executable(${CMAKE_PROJECT_NAME}
               source/main.cpp)

add_executable(${CMAKE_PROJECT_NAME}_tests
               tests/unit-test.cpp)

#------------------------------------------------------------------------------
# Compiler flags
#------------------------------------------------------------------------------
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wfatal-errors -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-variadic-macros")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")

#------------------------------------------------------------------------------
# Packages
#------------------------------------------------------------------------------
# - OpenGL
#------------------------------------------------------------------------------
find_package(OpenGL REQUIRED)
# find_package(GLM REQUIRED)

if(NOT OPENGL_FOUND)
	message(FATAL_ERROR "OpenGL not found !")
endif(NOT OPENGL_FOUND)

# if(NOT GLM_FOUND)
# 	message(FATAL_ERROR "glm not found !")
# endif(NOT GLM_FOUND)
#
# include_directories(${GLM_INCLUDE_DIRS})

#------------------------------------------------------------------------------
# - SDL2, SDL2_image, SDL2_mixer
#------------------------------------------------------------------------------
include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer)

if(NOT SDL2_FOUND)
	message(FATAL_ERROR "SDL2 not found !")
endif(NOT SDL2_FOUND)

if(NOT SDL2IMAGE_FOUND)
	message(FATAL_ERROR "SDL2_image not found !")
endif(NOT SDL2IMAGE_FOUND)

if(NOT SDL2MIXER_FOUND)
	message(FATAL_ERROR "SDL2_mixer not found !")
endif(NOT SDL2MIXER_FOUND)

include_directories(${SDL2_INCLUDE_DIRS}
                    ${SDL2IMAGE_INCLUDE_DIRS}
                    ${SDL2MIXER_INCLUDE_DIRS})

#------------------------------------------------------------------------------
# Link options
#------------------------------------------------------------------------------
target_link_libraries(${CMAKE_PROJECT_NAME}_tests
                      ${CMAKE_PROJECT_NAME}_lib
                      ${OPENGL_LIBRARIES}
                      ${SDL2_LIBRARIES}
                      ${SDL2IMAGE_LIBRARIES}
                      ${SDL2MIXER_LIBRARIES})

target_link_libraries(${CMAKE_PROJECT_NAME}
                      ${CMAKE_PROJECT_NAME}_lib
                      ${OPENGL_LIBRARIES}
                      ${SDL2_LIBRARIES}
                      ${SDL2IMAGE_LIBRARIES}
                      ${SDL2MIXER_LIBRARIES})

