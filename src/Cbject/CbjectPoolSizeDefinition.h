#ifndef CBJECTPOOLSIZEDEFINITION_H
#define CBJECTPOOLSIZEDEFINITION_H

#define CbjectPoolSizeDefinition(klassName, poolSize) \
    enum                                              \
    {                                                 \
        klassName##_poolSize = poolSize               \
    }

#endif // CBJECTPOOLSIZEDEFINITION_H
