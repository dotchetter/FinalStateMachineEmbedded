#include <iostream>
#include "StateMachine.h"
#include "States.h"

void stateOne()
{
	std::cout << "State 1" << std::endl;
}

void stateTwo()
{
	std::cout << "State 2" << std::endl;
}

int main()
{
	fp_t f;

	StateMachine sm = StateMachine();
	sm.setMainState(&stateOne);

	f = sm.getMainState();
	f();

	sm.addState(&stateTwo, State::WAITING);
	f = sm.getState(State::WAITING);
	f();

	return 0;
}