#pragma once
#include <vector>

typedef void(*f_ptr);

class StateMachine
{
	std::vector<void(*)> methods;
	f_ptr mainState;

public:

	StateMachine();
	f_ptr getMainState();
	void setMainState(f_ptr* p);
	void addState(f_ptr* p, f_ptr* transition=NULL);
	
};