#ifndef ABSTRACT_VM_HPP
#define ABSTRACT_VM_HPP
#include "Operand_factory.hpp"
#include <regex>
#include <stack>
#include <string>
#include <vector>

class Abstract_vm
{
private:
	// initialize an array here that runs as a stack
	//for every new Operand created return a 
	//pointer of the class to the new space
	//of the stack
	std::stack<const IOperand*> vm_heap;
public:
	Abstract_vm();
	Abstract_vm(Abstract_vm const & src);
	~Abstract_vm();
	Operand_factory opFactory;

	//setter and getter
	void push_value(std::string value);
	const IOperand *pop();

	//abtract VM main instructions
	void dump();
	void assert(std::string value);
	void add();
	void sub();
	void mul();
	void div();
	void mod();
	void print();

	//this function could be used to call the instructions methods that can be private;
	void call_instructions(std::vector<std::string> instruction);
	eOperandType getOperandType(std::string operand);
	//exit(this one could be in another place)
};
#endif