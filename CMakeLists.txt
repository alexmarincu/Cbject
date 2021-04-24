cmake_minimum_required(VERSION 3.0.0)
project(Cbject VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCE
src/Cbject/Cbject.c
src/main.c
src/Application.c
src/Shape.c
src/Circle.c
src/Rectangle.c
src/ColoredCircle.c)

add_executable(Cbject ${SOURCE})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --save-temps")
include(CPack)
