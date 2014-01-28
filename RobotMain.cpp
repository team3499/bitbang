#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/BitBangCommand.h"
#include "CommandBase.h"

class RobotMain : public IterativeRobot {
private:
    Command *    bitBangCommand;
    LiveWindow * lw;

    virtual void RobotInit() {
        CommandBase::init();

        lw = LiveWindow::GetInstance();
    }

    virtual void AutonomousInit() {
        bitBangCommand = new BitBangCommand();
        bitBangCommand->Start();
    }

    virtual void AutonomousPeriodic() {
        Scheduler::GetInstance()->Run();
    }

    virtual void TeleopInit() {

    }

    virtual void TeleopPeriodic() {
        Scheduler::GetInstance()->Run();
    }

    virtual void TestPeriodic() {
        lw->Run();
    }
};

START_ROBOT_CLASS(RobotMain);

