#include "Commands/BitBangCommand.h"
#include "Timer.h"
#include "Utils/BitBangReport.h"

BitBangCommand::BitBangCommand() {
    Requires(gpioSubsystem);
    offset = 0;
    for (unsigned int i = 0; i < GetTimestampCount() ; i++) { timestamps[i] = 0; }
}


// Typical Results on cRIO4
// TS00:       3171 ns
// TS01:      23474 ns
// TS02:      29393 ns
// TS03:      30868 ns
// TS04:      36828 ns
// TS05:      38323 ns
// TS06:      44242 ns
// TS07:      45858 ns
// TS08:      51798 ns
// TS09:      53535 ns
// TS10:      59494 ns
// TS11:      60686 ns

void BitBangCommand::Initialize() {
    offset = GetTime();

    timestamps[0] = GetTime();
    gpioSubsystem->Set(1);
    gpioSubsystem->Set(0);
    timestamps[1] = GetTime();
    gpioSubsystem->Set(1);
    timestamps[2] = GetTime();
    for (volatile int i = 0 ; i < 2 ; i++) { }
    timestamps[3] = GetTime();
    gpioSubsystem->Set(0);
    timestamps[4] = GetTime();
    for (volatile int i = 0 ; i < 4 ; i++) { }
    timestamps[5] = GetTime();
    gpioSubsystem->Set(1);
    timestamps[6] = GetTime();
    for (volatile int i = 0 ; i < 8 ; i++) { }
    timestamps[7] = GetTime();
    gpioSubsystem->Set(0);
    timestamps[8] = GetTime();
    for (volatile int i = 0 ; i < 16 ; i++) { }
    timestamps[9] = GetTime();
    gpioSubsystem->Set(1);
    timestamps[10] = GetTime();
    timestamps[11] = GetTime();

}

void BitBangCommand::Execute() {

}

bool BitBangCommand::IsFinished() {
    return true;
}

void BitBangCommand::End() {
    BitBangReport report;
    report.Report(this);
}

void BitBangCommand::Interrupted() {
    End();
}

double BitBangCommand::GetTimestamp(unsigned int index) const {
    if (index < BIT_BANG_COMMAND_TIMESTAMP_COUNT) {
        return (timestamps[index] - offset) * 1000000000;
    }
    return 0;
}

unsigned int BitBangCommand::GetTimestampCount() const {
    return BIT_BANG_COMMAND_TIMESTAMP_COUNT;
}
