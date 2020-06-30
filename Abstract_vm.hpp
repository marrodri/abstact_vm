#ifndef ABSTRACT_VM_HPP
#define ABSTRACT_VM_HPP
#include "Operand_factory.hpp"
#include "VM_exceptions.hpp"
#include <regex>
#include <stack>
#include <map>
#include <string>
#include <vector>

typedef std::vector<std::vector<std::string>> t_double_vector_string;

enum eInstructionValue	{ push_val, pop_val, 
						dump_val, assert_val, add_val,
						sub_val, mul_val, div_val, mod_val,
						print_val, exit_val };

class Abstract_vm
{
private:
	/*
	** initialize an array here that runs as a stack
	** for every new Operand created return a 
	** pointer of the class to the new space
	** of the stack
	*/

	std::stack<const IOperand*> vm_heap;
	std::map<std::string, eOperandType> operandTypes_map;
	std::map<std::string, eInstructionValue> instructionTypes_map;
	bool exit_bool = false;

	//abtract VM main instructions
	void push_value(std::string op_value, std::string num_value);
	void pop();
	void dump();
	void assert	(std::string op_value, std::string num_value);
	void add();
	void sub();
	void mul();
	void div();
	void mod();
	void print();
	void exit();

public:
	Abstract_vm();
	Abstract_vm(Abstract_vm const & src);
	~Abstract_vm();
	Operand_factory opFactory;	
	void operandTypes_map_init();
	void instructionsTypes_map_init();
	void run_instructions(t_double_vector_string instructions);
	void call_instruction(std::vector<std::string> instruction);
	std::map<std::string, eInstructionValue> get_instr_map();
};
#endif