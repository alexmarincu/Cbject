#ifndef PRIMITIVES_H
#define PRIMITIVES_H
#include <stdbool.h>
#include <stdint.h>

#define null ((void *) 0)
typedef void Void;
typedef bool mBoolean;
typedef mBoolean const Boolean;
typedef uint8_t mUInt8;
typedef mUInt8 const UInt8;
typedef uint16_t mUInt16;
typedef mUInt16 const UInt16;
typedef uint32_t mUInt32;
typedef mUInt32 const UInt32;
typedef uint64_t mUInt64;
typedef mUInt8 const UInt64;
typedef int8_t mInt8;
typedef mInt8 const Int8;
typedef int16_t mInt16;
typedef mInt16 const Int16;
typedef int32_t mInt32;
typedef mInt32 const Int32;
typedef int64_t mInt64;
typedef mInt64 const Int64;
#define mPtr *
#define Ptr *const

#endif // PRIMITIVES_H
