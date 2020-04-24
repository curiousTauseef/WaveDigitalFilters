#include "IdealVs.h"
#include "../GUI/IdealVsCell.h"

IdealVs::IdealVs() :
    voltage (new Property ({"Voltage", 0.0f, -20.0f, 20.0f}))
{
    cell = std::make_unique<IdealVsCell> (*this);

    voltage->valueChanged = [=]
    {
        if (! getInput())
            setVoltage (voltage->value);
    };

    props.add (voltage);
}

void IdealVs::setInput (bool input)
{
    Source::setInput (input);

    if (! getInput())
        setVoltage (voltage->value);
}

void IdealVs::setVoltage (float voltageValue)
{
    if (auto vs = dynamic_cast<WaveDigitalFilter::IdealVoltageSource*> (wdf.get()))
        vs->setVoltage (voltageValue);        
}

bool IdealVs::prepare (double sampleRate)
{
    wdf = std::make_unique<WaveDigitalFilter::IdealVoltageSource>();
    setVoltage (voltage->value);

    bool result = RootNode::prepare (sampleRate);

    if (result)
    {
        inputFunc = [=] (double x)
        {
            dynamic_cast<WaveDigitalFilter::IdealVoltageSource*> (wdf.get())->setVoltage (x);
        };
    }

    return result;
}
