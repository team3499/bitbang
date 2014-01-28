#ifndef __BIT_BANG_COMMAND_H__
#define __BIT_BANG_COMMAND_H__

#include "CommandBase.h"

#define BIT_BANG_COMMAND_TIMESTAMP_COUNT 12

class BitBangCommand : public CommandBase {
  public:
    BitBangCommand();

    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();

    double       GetTimestamp(unsigned int index) const;
    unsigned int GetTimestampCount() const;

  private:
    double timestamps[BIT_BANG_COMMAND_TIMESTAMP_COUNT];
};

#endif /* __BIT_BANG_COMMAND_H__ */
