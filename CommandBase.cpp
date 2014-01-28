#include "CommandBase.h"
#include "Robotmap.h"

CommandBase::CommandBase(const char * name) : Command(name) {

}

CommandBase::CommandBase() : Command() {

}

// Initialize a single static instance of all of your subsystems to NULL
GPIOSubsystem * CommandBase::gpioSubsystem = NULL;
OI *            CommandBase::oi            = NULL;

void CommandBase::init() {
    gpioSubsystem = new GPIOSubsystem(GPIO_CHANNEL);
    oi            = new OI();
}
