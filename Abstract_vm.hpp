#ifndef ABSTRACT_VM_HPP
#define ABSTRACT_VM_HPP
#include "IOperand.hpp"
#include <stack>
#include <string>
#include <vector>
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"


// FACTORY !!!
typedef std::string t_string;
class Abstract_vm
{
private:
	// initialize an array here that runs as a stack
	//for every new Operand created return a 
	//pointer of the class to the new space
	//of the stack
	std::stack<IOperand> vm_heap;
public:
	Abstract_vm();
	Abstract_vm(Abstract_vm const & src);
	~Abstract_vm();

	//set function
	//setter's are like the push value, so it should be fine
	//push VALUE
	//from the parameters, it will call the IOperand create* function
	//with the value inputed, and then it will be push to the stack
	void push_value(std::string value);
	
	//get function
	//getter for the stack, like pop()??
	IOperand *pop();

	void dump(); //check how it works
	void assert(std::string value);

	//add
	//pops the top 2 values, then it makes the sum of those popped values,
	//and the result is pushed back to the stack
	void add();
	void sub();
	void mul();
	//same as previous but with division, there's an edge case to check
	void div();
	//there's an edge case to check for mod too
	void mod();
	void print();
	
	//this function could be used to call the instructions methods that can be private;
	void call_instructions(std::vector<std::string> instruction);

	//exit(this one could be in another place)



};
#endif