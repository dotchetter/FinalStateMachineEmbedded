#pragma once
#include "States.h"
#include "StateMachine.h"
#include <map>
#include <vector>

typedef void (*fp_t)();

class StateMachine
/*
* State machine class.
* Maximum amount of methods mapped: 128
*
* This object allows for continuous
* polymorphic access to state methods in
* a call stack. It aids to automate the
* transition between different function
* calls after a set of pre-determined set
* of states.
*
* The mainState and mainMethod correlate
* to the "idle" state of the device, and
* will automatically be the default yield
* whenever the previous state has exhausted
* and the method getCurrentState is called
* once again. It will remain the result
* until methods with access mutate the state
* through passing an enum instance for the
* desired state. If however the transitional
* state mismatches with the predefined
* transitional state and a method tries to
* switch to an illegal state, this is prohibited
* and automatically reverts to the main state
* and ignores the attempted transition.
*
* For custom transitions to be allowed, e.g.:
*
	* blinkLed -> runMotor
*
* .. instead of the default, which would be:
*
	* blinkLed -> mainState
*
* .. the StateMachine instance must be provided
* with this breadcrum trail upon defining the
* method in the addMethod call.
*
* It is as easy as adding the optional
* "transition" parameter in the function call,
* defining an enum to the desired transitional
* state. For this to be supported, the transitional
* state must be implemented before the state which
* uses it as a transition.
*/
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