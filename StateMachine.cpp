#pragma once
#include "StateMachine.h"

StateMachine::StateMachine(fp_t mainState)
{
	this->mainState = mainState;
}

fp_t StateMachine::getMainState()
{
	return this->mainState;
}


fp_t StateMachine::getState(State state)
{
	fp_t func;

	try
	{
		func = this->methods.at(state);
	}
	catch (const std::exception&)
	{
		func = nullptr;
	}
	return func;
}

void StateMachine::addState(fp_t func, State state)
{
	this->methods[state] = func;
}