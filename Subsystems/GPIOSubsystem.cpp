#include "Subsystems/GPIOSubsystem.h"
#include "DigitalOutput.h"

GPIOSubsystem::GPIOSubsystem(int channel) : Subsystem("GPIOSubsystem") {
    gpio = new DigitalOutput(channel);
}

void GPIOSubsystem::Set(int value) {
    gpio->Set(value);
}
