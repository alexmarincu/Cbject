#ifndef OBJ_H
#define OBJ_H
#include "../CObjectUtilities.h"

typedef struct Obj Obj;
Void Obj_init(Obj * const this_);
UInt8 Obj_size(Obj const * const this_);
char const * Obj_type(Obj const * const this_);
UInt8 ObjClass_size();

#endif // OBJ_H
