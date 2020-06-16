#ifndef OP_EXCEPTIONS_HPP
#define OP_EXCEPTIONS_HPP
#include <iostream>
#include <exception>

class Op_exceptions : public std::exception
{	
public:
	void overflow();
	void underflow();
	void div_by_zero();
	void mod_by_zero();

} op_error;
#endif