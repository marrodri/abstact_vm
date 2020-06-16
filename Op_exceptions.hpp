#ifndef OP_EXCEPTIONS_HPP
#define OP_EXCEPTIONS_HPP
#include <iostream>
#include <exception>

class Op_exceptions : public std::exception
{
private:
	
public:
	Op_exceptions();
	Op_exceptions(Op_exceptions const & src);
	~Op_exceptions();

	Op_exceptions & operator=(Op_exceptions const & rhs);

	//get function
	
	//set function
	void overflow();
	void underflow();
	void div_by_zero();
	void mod_by_zero();

} op_error;
#endif