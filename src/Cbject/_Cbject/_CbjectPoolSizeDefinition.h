#ifndef _CBJECTPOOLSIZEDEFINITION_H
#define _CBJECTPOOLSIZEDEFINITION_H

#define _CbjectPoolSizeDefinition(cbjectTypeName, poolSize) \
    enum                                               \
    {                                                  \
        cbjectTypeName##_poolSize = poolSize                \
    }

#endif // _CBJECTPOOLSIZEDEFINITION_H
