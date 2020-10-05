#include <iostream>
#include "StateMachine.h"

void stateOne()
{
	std::cout << "State 1" << std::endl;
}

int main()
{
	StateMachine sm = StateMachine();
	sm.setMainState(&stateOne);

	fp_t f = sm.getMainState();
	f();

	return 0;
}