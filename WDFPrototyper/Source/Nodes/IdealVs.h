#ifndef IDEALVS_H_INCLUDED
#define IDEALVS_H_INCLUDED

#include "RootNode.h"
#include "Source.h"

class IdealVs : public RootNode,
                public Source
{
public:
    IdealVs();
    ~IdealVs() {}

    bool prepare (double sampleRate);

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (IdealVs)
};

#endif // IDEALVS_H_INCLUDED
