#ifndef STANDARDTYPES_H
#define STANDARDTYPES_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define null NULL

typedef void _Void;
typedef _Void const Void;
typedef bool _Boolean;
typedef _Boolean const Boolean;
typedef uint8_t _UInt8;
typedef _UInt8 const UInt8;
typedef uint16_t _UInt16;
typedef _UInt16 const UInt16;
typedef uint32_t _UInt32;
typedef _UInt32 const UInt32;
typedef uint64_t _UInt64;
typedef _UInt8 const UInt64;
typedef int8_t _Int8;
typedef _Int8 const Int8;
typedef int16_t _Int16;
typedef _Int16 const Int16;
typedef int32_t _Int32;
typedef _Int32 const Int32;
typedef int64_t _Int64;
typedef _Int64 const Int64;
#define _Ref *
#define Ref *const

#endif // STANDARDTYPES_H
