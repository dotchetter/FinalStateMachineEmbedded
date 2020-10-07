#include <iostream>
#include "StateMachine.h"
#include "States.h"

void proximityRead();
void checkKeyPressed();
void stopMotors();
void idle();

StateMachine sm = StateMachine(&idle, State::IDLE);

void proximityRead()
{
	std::cout << "Reading proximity sensor" << std::endl;
	sm.release();
}

void stopMotors()
{
	std::cout << "Stopping stepper motors" << std::endl;
	sm.release();
}

void checkKeyPressed()
{
	std::cout << "Checking if key is pressed" << std::endl;
	sm.release();
}

void idle()
{
	static int count;

	if (!(count % 2))
	{
		std::cout << "idle: Changing state to read proximity" << std::endl;
		sm.transitionTo(State::READ_PROXIMITY_SENSOR);
	}
	else
	{
		std::cout << "idle: Changing state to stop motors" << std::endl;
		sm.transitionTo(State::STOP_MOTORS);
	}
	count++;
}

int main()
{

	fp_t f;

	sm.addState(&checkKeyPressed, State::CHECK_KEY_PRESS);
 	sm.addState(&proximityRead, State::READ_PROXIMITY_SENSOR);
	sm.addState(&stopMotors, State::STOP_MOTORS, State::CHECK_KEY_PRESS);

	while (1)
	{
		sm.next()();
		getchar();
	}
}