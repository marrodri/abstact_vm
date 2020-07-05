#ifndef IOPERAND_HPP
#define IOPERAND_HPP
#include <string>
#include <iostream>
#include <stddef.h>
#include <algorithm>
// #include "Operand_factory.hpp"
/*
** this class gets inherited by all other operands,
** so all operands classes become IOperands.
*/

//ask if it should be a plain type or a class type for the enum
enum eOperandType
{
	int8, int16, int32, float_class, double_class
};

class IOperand {
public:
	// IOperand(){};
	virtual	~IOperand( void ) {};

	//virtual functions for the operand classes
	virtual int				getPrecision( void ) const = 0; //precision of the type of the instance
	virtual eOperandType	getType(void) const = 0; //type of the instance

	//OPERATORS for the OPERANDS
	virtual IOperand const	*operator+(IOperand const & rhs) const = 0;
	virtual IOperand const	*operator-(IOperand const & rhs) const = 0;
	virtual IOperand const	*operator*(IOperand const & rhs) const = 0;
	virtual IOperand const	*operator/(IOperand const & rhs) const = 0;
	virtual IOperand const	*operator%(IOperand const & rhs) const = 0;

	//string representation of the instance
	virtual std::string const & toString( void ) const  = 0; //string representation of the instance
};
#endif