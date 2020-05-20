#ifndef VM_STACK_HPP
#define VM_STACK_HPP
#include "IOperand.hpp"
#include <stack>

class vm_stack
{
private:
	// initialize an array here that runs as a stack
	//for every new Operand created return a 
	//pointer of the class to the new space
	//of the stack
	std::stack<IOperand> vm_heap;
public:
	vm_stack();
	vm_stack(vm_stack const & src);
	~vm_stack();


	//function for the stack to do
	//push VALUE
	//from the parameters, it will call the IOperand create* function
	//with the value inputed, and then it will be push to the stack

	//pop function
	//call the pop function to the private stack

	//dump
	//check how it works

	//assert VALUE

	//add
	//pops the top 2 values, then it makes the sum of those popped values,
	//and the result is pushed back to the stack

	//sub

	//mul

	//div
	//same as previous but with division, there's an edge case to check

	//mod
	//there's an edge case to check for mod too

	//print
	

	//exit(this one could be in another place)


	//get function
	//set function

};
#endif