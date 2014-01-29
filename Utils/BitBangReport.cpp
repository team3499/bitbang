#include "Utils/BitBangReport.h"
#include "SerialPort.h"

void BitBangReport::Report(BitBangCommand * command) {
    for (unsigned int i = 0 ; i < command->GetTimestampCount() ; i++) {
        printf("TS%02d: %10.0f ns\n", i, command->GetTimestamp(i));
    }
}
