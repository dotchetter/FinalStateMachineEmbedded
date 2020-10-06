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

	for (int i = 0; i < lastAddedState; i++)
	{
		if (states[i] == state)
		{
			return methods[i];
		}
	}return nullptr;
}

void StateMachine::addState(fp_t func, State state)
{
	if (this->lastAddedState > sizeof(this->methods) / sizeof(this->methods[0]))
	{
		return;
	}
	this->methods[this->lastAddedState] = func;
	this->states[this->lastAddedState] = state;
	this->lastAddedState++;
}