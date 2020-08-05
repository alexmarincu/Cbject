#ifndef PRIMITIVES_H
#define PRIMITIVES_H
#include <stdbool.h>
#include <stdint.h>

#define null 0
typedef void Void;
typedef bool Boolean;
typedef uint8_t Byte;
typedef uint8_t UInt8;
typedef uint16_t UInt16;
typedef uint32_t UInt32;
typedef uint64_t UInt64;
typedef int8_t Int8;
typedef int16_t Int16;
typedef int32_t Int32;
typedef int64_t Int64;
typedef float Float;
#define Array_size(array) (sizeof(array) / sizeof(*(array)))

#endif // PRIMITIVES_H
