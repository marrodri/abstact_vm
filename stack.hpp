#ifndef STACK_HPP
#define STACK_HPP
#include "IOperand.hpp"

class stack
{
private:
	
public:
	stack();
	stack(stack const & src);
	~stack();

	//public functions that can be accessed
	//anywhere, it could be more better if
	//protected, or if just in case, private

	//push
	//pop
	//dump
	//assert
	//add
	//sub
	//mul
	//div
	//mod
	//print
	
	stack & operator=(stack const & rhs);

	//get function
	//set function

};
#endif