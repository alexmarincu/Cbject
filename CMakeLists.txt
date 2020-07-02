cmake_minimum_required(VERSION 3.0.0)
project(CObject VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCE
src/main.c
src/App/App.c
src/CObject/CObject.c
src/Shape/Shape.c
src/Circle/Circle.c
src/Rectangle/Rectangle.c
src/ColoredCircle/ColoredCircle.c)

add_executable(CObject ${SOURCE})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
