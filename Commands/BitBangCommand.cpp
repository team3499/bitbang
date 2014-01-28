#include "Commands/BitBangCommand.h"

BitBangCommand::BitBangCommand() {
    Requires(gpioSubsystem);
    for (unsigned int i = 0; i < GetTimestampCount() ; i++) { timestamps[i] = 0; }
}

void BitBangCommand::Initialize() {
    // TODO Bang the Bits
}

void BitBangCommand::Execute() {

}

bool BitBangCommand::IsFinished() {
    return true;
}

void BitBangCommand::End() {
    // TODO Output Report
}

void BitBangCommand::Interrupted() {
    End();
}

double BitBangCommand::GetTimestamp(unsigned int index) const {
    if (index < BIT_BANG_COMMAND_TIMESTAMP_COUNT) {
        return timestamps[index];
    }
    return 0;
}

unsigned int BitBangCommand::GetTimestampCount() const {
    return BIT_BANG_COMMAND_TIMESTAMP_COUNT;
}
