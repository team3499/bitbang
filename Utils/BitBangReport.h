#ifndef __BIT_BANG_REPORT_H__
#define __BIT_BANG_REPORT_H__

#include "Commands/BitBangCommand.h"

/**
 * Output a report to the serial port showing the results 
 * from a BitBangCommand run.
 */
class BitBangReport {
  public:
    void Report(BitBangCommand * command);

};

#endif /* __BIT_BANG_REPORT_H__ */
