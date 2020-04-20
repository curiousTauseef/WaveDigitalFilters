#ifndef IDS_H_INCLUDED
#define IDS_H_INCLUDED

namespace IDs
{
    enum Leaf
    {
        Resistor,
        Capacitor,
        Inductor,
    };

    enum Adaptor
    {
        Series,
        Parallel,
        Inverter,
    };
};

#endif // IDS_H_INCLUDED
