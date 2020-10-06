#pragma once
#include "States.h"
#include "StateMachine.h"
#include <map>
#include <vector>

typedef void (*fp_t)();

class StateMachine
{
	int lastAddedState;
	fp_t methods[256];
	State states[256];
	fp_t mainState;

public:

	StateMachine(fp_t mainState);
	fp_t getMainState();
	fp_t getState(State state);
	void addState(fp_t func, State state);
};