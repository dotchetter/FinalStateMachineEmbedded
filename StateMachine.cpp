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


const State StateMachine::getTransitionalStateForState(State state)
/*
* Get the next state in line, as per defined
* by the given state the machine is currently
* in at the time of calling. The default is 
* the mainState state as a failsafe fallback,
* if loop exhausts without finding a matching
* transition for the current state. 
*/
{
	for (int i = 0; i < this->stateCount; i++)
	{
		if (this->states[i] == state)
		{
			return this->transitionalStates[i];
		}
	}
	return this->mainState;
}
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