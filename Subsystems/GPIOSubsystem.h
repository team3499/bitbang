#ifndef __GPIO_SUBSYSTEM_H__
#define __GPIO_SUBSYSTEM_H__

#include "WPILib.h"

/**
 * GPIO Outout on FRC Digital Sidecar
 */
class GPIOSubsystem : public Subsystem {
  public:
    GPIOSubsystem(int channel);

    void Set(int value);

  private:
    DigitalOutput * gpio;

};
#endif /* __GPIO_SUBSYSTEM_H__ */
