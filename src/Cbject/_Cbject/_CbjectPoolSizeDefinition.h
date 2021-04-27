#ifndef _CBJECTPOOLSIZEDEFINITION_H
#define _CBJECTPOOLSIZEDEFINITION_H

#define _CbjectPoolSizeDefinition(klassName, poolSize) \
    enum                                               \
    {                                                  \
        klassName##_poolSize = poolSize                \
    }

#endif // _CBJECTPOOLSIZEDEFINITION_H
