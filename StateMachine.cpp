#pragma once
#include "StateMachine.h"
#include <iostream>

template<class State>
StateMachine<State>::StateMachine(fp_t mainMethod, State state)
{
	this->mainMethod = mainMethod;
	this->mainState = mainState;
}

template<class State>
const State StateMachine<State>::getMainState()
/*
* Returns the main state of the State Machine.
*/
{
	return this->mainState;
}

template<class State>
const State StateMachine<State>::getCurrentState()
/*
* Returns the state the State Machine is in
* at the time of calling.
*/
{
	return this->currentState;
}

template<class State>
const State StateMachine<State>::getChainedStateForState(State state)
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
			return this->chainedStates[i];
		}
	}
	return this->mainState;
}

template<class State>
const fp_t StateMachine<State>::getMethodForState(State state)
/*
* Iterate over the states and return the method
* on the same index position as the given state
* in the linked arrays.
*/
{
	for (int i = 0; i < this->stateCount; i++)
	{
		if (states[i] == state)
		{
			return this->methods[i];
		}
	}return this->mainMethod;
}

template<class State>
void StateMachine<State>::release()
/*
* Mutates the instance's currentState to whichever
* state is defined as the transitional state for 
* the state the machine is in at the given time 
* of call.
*/
{
	this->nextState = this->getChainedStateForState(this->currentState);
}

template<class State>
void StateMachine<State>::transitionTo(State state)
/*
* Allows methods to mutate the state of the machine
* to transition to another method in the call stack.
* It is however only allowed if the current state is
* the main state, that is, it cannot interrupt an
* ongoing transition between one secondary state and 
* another. 
*/
{
	if (this->currentState == this->mainState)
	{
		this->nextState = state;
	}
}

template<class State>
const fp_t StateMachine<State>::next()
/*
* Allows for a continuous polling method to be called
* which returns the method for the state the machine
* is in at the time of call. The previous state is cached
* as to reduce lookup time and CPU cycles spent on searching,
* if the state from the previous call is left unchanged.
* 
* Protects the application from an infinite loop where
* the state is left unchanged by misbehaving state methods
* which do not call the transition() method. This validation
* is implemented by not allowing the same state to occur twice
* or more in sequence.
*/
{
	
	if (this->currentState == this->nextState)
	{
		this->nextState = this->mainState;
	}

	this->currentState = this->nextState;
	return this->getMethodForState(this->nextState);
}

template<class State>
void StateMachine<State>::addState(fp_t func, State state)
/*
* Add states to the state machine. 
* 
* parameter func (function pointer fp_t):
*	Denotes which method/function to add as a state
* 
* parameter state
*	Denotes which state identifier to bind to the 
*   function / method defined as 'func' parameter. 
*   This can be seen as the 'key' in a key/value
*   structure. This can be anything. A custom class,
*   instance of custom class, int, string, etcetera.
*   The recommended way for scaleable code is to write
*   an enum class and use enum instance, named after the
*   function. 
*/
{
	if (this->stateCount < sizeof(this->methods) / sizeof(this->methods[0]))
	{
		this->methods[this->stateCount] = func;
		this->states[this->stateCount] = state;
		this->chainedStates[this->stateCount] = this->mainState;
		this->stateCount++;
	}
}

template<class State>
void StateMachine<State>::setChainedState(State primary, State secondary)
/*
* Define a state which should run after a state.
* 
* This is useful when the desired behavior is
* a scenario where the user would like the 
* state to not return to the main state when 
* a given state is exhausted, but that another
* state is called. 
* 
* RESTRICTIONS / IGNORED CASES:
* 
* Both the primary and secondary state must be 
* added using the addState() method prior to 
* calling this method.
* 
* One state cannot chain itself. If primary and 
* secondary are identical, the chain is ignored.
*/
{
	if (primary == secondary)
		return;

	for (int i = 0; i < sizeof(this->states) / sizeof(this->states[0]); i++)
	{
		if (this->states[i] == primary)
		{
			this->chainedStates[i] = secondary;
		}
	}
}