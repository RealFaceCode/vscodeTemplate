cmake_minimum_required(VERSION 3.19)
project(App VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/arch)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE SOURCE_FILES "project/*.cpp" "project/*.hpp" "project/*.c" "project/*.h")

add_subdirectory("dependencies/freetype")
add_subdirectory("dependencies/glew-cmake/build/cmake")
add_subdirectory("dependencies/glfw")

find_package(OpenGL REQUIRED)
message(STATUS "OPENGL_FOUND:= ${OPENGL_FOUND}")

if(OPENGL_FOUND)
    message('OPENGL_FOUND-is-true')
else()
    message('OPENGL_FOUND-is-false')
endif()

message(STATUS "OPENGL_INCLUDE_DIR:= ${OPENGL_INCLUDE_DIR}")
message(STATUS "OPENGL_LIBRARY:= ${OPENGL_LIBRARY}")
message(STATUS "OPENGL_LIBRARIES:= ${OPENGL_LIBRARIES}")

add_executable(App ${SOURCE_FILES})
target_link_libraries(App freetype ${OPENGL_LIBRARIES} glew_s glfw)

target_include_directories(App PUBLIC
    dependencies/glfw/include
    dependencies/glew-cmake/include
    dependencies/glm
    dependencies/freetype/include
    ${OPENGL_INCLUDE_DIR}
)