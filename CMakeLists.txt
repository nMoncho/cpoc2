cmake_minimum_required(VERSION 2.8)

project(cpoc2)

FILE(GLOB SOURCE_FILES src/*.cpp)

add_executable(cpoc2
    ${SOURCE_FILES}
    deps/lodepng/lodepng.cpp
#    deps/glew/src/glew.c

#    deps/noise/noise.c
#    deps/sqlite/sqlite3.c
#    deps/tinycthread/tinycthread.c
)

#add_definitions(-std=c99 -O3)

add_subdirectory(deps)
include_directories(
  deps/glew-1.13.0/include
  deps/glfw-3.1.2/include
  deps/glm-0.9.7.1
  deps/lodepng
  deps/sqlite
  .
)


set(ALL_LIBS
  ${OPENGL_LIBRARY}
  glfw
  GLEW_1130
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

if(MINGW)
    set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH}
        "C:/Program Files/CURL/lib" "C:/Program Files (x86)/CURL/lib")
    set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH}
        "C:/Program Files/CURL/include" "C:/Program Files (x86)/CURL/include")
endif()

find_package(CURL REQUIRED)
find_package(OpenGL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

#if(APPLE)
#    target_link_libraries(cpoc2 glfw
#        ${GLFW_LIBRARIES} ${CURL_LIBRARIES})
#endif()

#if(UNIX)
#    target_link_libraries(cpoc2 dl glfw
#        ${GLFW_LIBRARIES} ${CURL_LIBRARIES})
#endif()

#if(MINGW)
#    target_link_libraries(cpoc2 ws2_32.lib glfw
#        ${GLFW_LIBRARIES} ${CURL_LIBRARIES})
#endif()

target_link_libraries(cpoc2
	${ALL_LIBS}
)