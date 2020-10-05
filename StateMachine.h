#pragma once
#include <vector>

typedef void (*fp_t)();

class StateMachine
{
	std::vector<fp_t> methods;
	fp_t mainState;

public:

	StateMachine();

	fp_t getMainState();
	void setMainState(fp_t func);
	void addState(fp_t func);
};