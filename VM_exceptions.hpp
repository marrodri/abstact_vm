#ifndef VM_EXCEPTIONS_HPP
#define VM_EXCEPTIONS_HPP
#include <iostream>
#include <exception>

class VM_exceptions : public std::exception
{	
public:
	//TODO

	// -lexical and/or syntatic errors
	void lexical_error();
	// -unknown instructions
	void unknown_instruction();
	// -pop on an empty stack
	void empty_stack();

	// -when using arithmetic when the stack has less than 2 values
	void not_enough_operands();

	// -the program doesn't have an exit instruction
	void no_exit();

	// -an assert instruction is not true
	void wrong_assert();
};
#endif