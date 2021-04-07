cmake_minimum_required(VERSION 3.0.0)
project(CObject VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCE
src/CObject/Object/Object.c
src/main.c
src/Application/Application.c
src/Shape/Shape.c
src/Circle/Circle.c
src/Rectangle/Rectangle.c
src/ColoredCircle/ColoredCircle.c)

add_executable(CObject ${SOURCE})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --save-temps")
include(CPack)
