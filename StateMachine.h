#pragma once
#include "States.h"
#include "StateMachine.h"
#include <map>
#include <vector>

typedef void (*fp_t)();

class StateMachine
{
	std::map<State, fp_t> methods;
	std::map<fp_t, std::vector<State>> stateMap;
	fp_t mainState;
	fp_t lastPolledState;

public:

	StateMachine(fp_t mainState);
	fp_t getMainState();
	fp_t getState(State state);
	void addState(fp_t func, State state);
};