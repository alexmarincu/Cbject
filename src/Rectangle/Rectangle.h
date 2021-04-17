#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "../Shape/Shape.h"

#define class Rectangle
#define superClass Shape

Class(
    InitParams(
        uint32 const width,
        uint32 const height),
    Members(
        uint32 width,
        uint32 height),
    VirtualFunctions((void, rotate, ())));

// CbjectPreprocessor_virtualFunctionsTypeDefinition(ccc);

Setters(
    (uint32, width),
    (uint32, height));

Getters(
    (uint32, width),
    (uint32, height));

Function(uint32, test, (uint32 const a));

#undef superClass
#undef class
#endif // RECTANGLE_H
