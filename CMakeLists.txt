#------------------------------------------------------------------------------
# CMakeLists.txt
# By Quent42340 <quent42340@gmail.com>
#------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.1)

project(ZeldaOOL VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

#------------------------------------------------------------------------------
# Get source files
#------------------------------------------------------------------------------
file(GLOB_RECURSE SOURCE_FILES source/*.cpp external/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.hpp external/*.hpp)

foreach(HEADER_FILE ${HEADER_FILES})
	get_filename_component(HEADER_DIRECTORY ${HEADER_FILE} DIRECTORY)
	include_directories(${HEADER_DIRECTORY})
endforeach(HEADER_FILE)

#------------------------------------------------------------------------------
# Add executables
#------------------------------------------------------------------------------
add_executable(${CMAKE_PROJECT_NAME}
               ${SOURCE_FILES})

#------------------------------------------------------------------------------
# Compiler flags
#------------------------------------------------------------------------------
# target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -O3 -ffast-math)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -g -Wall -Wextra -Wfatal-errors -Wno-variadic-macros)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -DDEBUG_ENABLED -DDEBUG_COLOR)
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_14)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
endif()

#------------------------------------------------------------------------------
# Packages
#------------------------------------------------------------------------------
# - gamekit
#------------------------------------------------------------------------------
find_package(GameKit REQUIRED)
if(NOT GAMEKIT_FOUND)
	message(FATAL_ERROR "gamekit is needed to build the project. Please install it correctly.")
endif()

include_directories(${GAMEKIT_INCLUDE_DIR})
link_directories(${GAMEKIT_LIBRARY_DIRS})

#------------------------------------------------------------------------------
# - tinyxml2
#------------------------------------------------------------------------------
find_package(TinyXml2 REQUIRED)
if(NOT TINYXML2_FOUND)
	message(FATAL_ERROR "tinyxml2 is needed to build the project. Please install it correctly.")
endif()

include_directories(${TINYXML2_INCLUDE_DIR})
link_directories(${TINYXML2_LIBRARY_DIRS})

#------------------------------------------------------------------------------
# - OpenGL
#------------------------------------------------------------------------------
set(OpenGL_GL_PREFERENCE "LEGACY")

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
# - SFML
#------------------------------------------------------------------------------
find_package(SFML COMPONENTS audio graphics system window REQUIRED)

include_directories(${SFML_INCLUDE_DIRS})

#------------------------------------------------------------------------------
# Link options
#------------------------------------------------------------------------------
target_link_libraries(${CMAKE_PROJECT_NAME}
                      ${GAMEKIT_LIBRARIES}
                      ${TINYXML2_LIBRARIES}
                      ${OPENGL_LIBRARIES}
                      sfml-system
                      sfml-window
                      sfml-audio
                      sfml-graphics)

