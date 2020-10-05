#pragma once
#include "StateMachine.h"
#include <vector>

StateMachine::StateMachine()
{
}

fp_t StateMachine::getMainState()
{
	return this->mainState;
}

void StateMachine::setMainState(fp_t func)
{
	this->mainState = func;
}

void StateMachine::addState(fp_t func)
{
	this->methods.push_back(func);
}