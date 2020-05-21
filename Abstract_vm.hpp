#ifndef ABSTRACT_VM_HPP
#define ABSTRACT_VM_HPP
#include "IOperand.hpp"
#include <stack>
#include <string>
#include <vector>
#include "Int8.hpp"


// FACTORY !!!
class Abstract_vm
{
private:
	// initialize an array here that runs as a stack
	//for every new Operand created return a 
	//pointer of the class to the new space
	//of the stack
	std::stack<IOperand> vm_heap;

	//each function will create a class with the value added, and
	//pushed right away into the stack

	//testing, for creating an int8 class
	IOperand const * createInt8(std::string const & value) const;

	IOperand const * createInt16(std::string const & value) const;
	IOperand const * createInt32(std::string const & value) const;
	IOperand const * createFloat(std::string const & value) const;
	IOperand const * createDouble(std::string const & value) const;

public:
	Abstract_vm();
	Abstract_vm(Abstract_vm const & src);
	~Abstract_vm();

	//use a switch case
	//CreateOperand(class of the operand, input string the value int);
	//use an array to check if the operand exists or not, if it exists then create
	//if not handle error by saying operand type doesn't exist
	IOperand const * createOperand(eOperandType type, std::string const & value) const;
	
	//get function
	//getter for the stack, like pop()??
	
	//set function
	//setter's are like the push value, so it should be fine

		//function for the stack to do
	//push VALUE
	//from the parameters, it will call the IOperand create* function
	//with the value inputed, and then it will be push to the stack
	void push_value(std::string value);

	//pop function
	//call the pop function to the private stack, returns the popped Ioperand value
	IOperand pop();

	//dump
	void dump();
	//check how it works

	//assert VALUE
	void assert(std::string value);

	//add
	//pops the top 2 values, then it makes the sum of those popped values,
	//and the result is pushed back to the stack
	void add();

	//sub
	void sub();

	//mul
	void mul();

	//div
	//same as previous but with division, there's an edge case to check
	void div();

	//mod
	//there's an edge case to check for mod too
	void mod();

	//print
	void print();

	void call_instructions(std::vector<std::string> instruction);

	//exit(this one could be in another place)



};
#endif