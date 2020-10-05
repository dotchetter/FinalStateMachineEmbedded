#pragma once
#include "States.h"
#include "StateMachine.h"
#include <map>

typedef void (*fp_t)();

class StateMachine
{
	std::map<State, fp_t> methods;
	fp_t mainState;

public:

	StateMachine();

	fp_t getMainState();
	fp_t getState(State state);
	void setMainState(fp_t func);
	void addState(fp_t func, State state);
};