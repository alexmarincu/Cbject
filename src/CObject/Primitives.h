#ifndef PRIMITIVES_H
#define PRIMITIVES_H
#include <stdbool.h>
#include <stdint.h>

#define null ((void *) 0)
typedef void Void;
typedef bool mBoolean;
typedef bool const Boolean;
typedef uint8_t mByte;
typedef uint8_t const Byte;
typedef uint8_t mUInt8;
typedef uint8_t const UInt8;
typedef uint16_t mUInt16;
typedef uint16_t const UInt16;
typedef uint32_t mUInt32;
typedef uint32_t const UInt32;
typedef uint64_t mUInt64;
typedef uint64_t const UInt64;
typedef int8_t mInt8;
typedef int8_t const Int8;
typedef int16_t mInt16;
typedef int16_t const Int16;
typedef int32_t mInt32;
typedef int32_t const Int32;
typedef int64_t mInt64;
typedef int64_t const Int64;
typedef float mFloat;
typedef float const Float;
#define mPtr *
#define Ptr *const

#endif // PRIMITIVES_H
