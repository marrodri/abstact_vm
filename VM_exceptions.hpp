#ifndef VM_EXCEPTIONS_HPP
#define VM_EXCEPTIONS_HPP
#include <iostream>
#include <exception>

class VM_exceptions : public std::exception
{
private:
	
public:
	VM_exceptions();
	VM_exceptions(VM_exceptions const & src);
	~VM_exceptions();

	VM_exceptions & operator=(VM_exceptions const & rhs);

	//get function
	//set function
	
	//TODO
	/*
	++++ABSTRACT_VM excpetions
	-lexical and/or syntatic errors
	
	-unknown instructions
	
	-divison/modulo by 0
	
	-pop on an empty stack
	
	-the program doesn't have an exit instruction
	
	-an assert instruction is not true
	
	-when using arithmetic when the stack has less than 2 values
	

	+OPERAND CLASSES EXCEPTIONS
	
	-overflow of a value
	
	-underflow of a value
	*/

};
#endif