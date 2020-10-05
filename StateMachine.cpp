#pragma once
#include "StateMachine.h"
#include <vector>

StateMachine::StateMachine(){}

f_ptr StateMachine::getMainState()
{
	return this->mainState;
}

void StateMachine::setMainState(f_ptr* p)
{
	this->mainState = p;
}

void StateMachine::addState(f_ptr* p, f_ptr* transition=NULL)
{
	this->methods.push_back(p);
}
