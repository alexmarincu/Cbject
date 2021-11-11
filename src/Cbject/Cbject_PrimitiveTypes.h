#ifndef CBJECT_PRIMITIVETYPES_H
#define CBJECT_PRIMITIVETYPES_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef uint8_t UInt8;
typedef uint16_t UInt16;
typedef uint32_t UInt32;
typedef uint64_t UInt64;
typedef int8_t Int8;
typedef int16_t Int16;
typedef int32_t Int32;
typedef int64_t Int64;
#define Array_size(array) (sizeof(array) / sizeof(array[0]))

#endif // CBJECT_PRIMITIVETYPES_H
