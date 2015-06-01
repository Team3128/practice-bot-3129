#include "WPILib.h"

#include <cmath>

/**
 * This starter template is for building a robot program from the
 * IterativeRobot base class.  This template does nothing - it merely
 * provides method stubs that you can use to begin your implementation.
 */
class PracticeBot : public SimpleRobot
{

	Joystick joystick;

	RobotDrive drive;

	public:
	PracticeBot()
	:joystick(1),
	 drive(1, 2, 3, 4)
	{
		drive.SetExpiration(.5);
	}

	/**
	 * Robot-wide initialization code should go here.
	 *
	 * Use this method for default Robot-wide initialization which will
	 * be called when the robot is first powered on.  It will be called exactly 1 time.
	 */
	void RobotInit()
	{
		printf("Team 3128 Practice Bot 2 C++ Program Starting\n");
	}

	void OperatorControl()
	{
		drive.SetSafetyEnabled(false);
		while(IsOperatorControl())
		{
			drive.ArcadeDrive(joystick);
			Wait(.005);
		}
	}

};

/*
 * This macro invocation tells WPILib that the named class is your "main" robot class,
 * providing an entry point to your robot code.
 */
START_ROBOT_CLASS(PracticeBot);

