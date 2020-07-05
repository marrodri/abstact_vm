#ifndef IOPERAND_HPP
#define IOPERAND_HPP
#include <string>
#include <iostream>
#include <stddef.h>
#include <algorithm>

enum eOperandType
{
	int8, int16, int32, float_class, double_class
};

class IOperand {
public:
	virtual	~IOperand( void ) {};

	virtual int				getPrecision( void ) const = 0; //precision of the type of the instance
	virtual eOperandType	getType(void) const = 0; //type of the instance

	virtual IOperand const	*operator+(IOperand const & rhs) const = 0;
	virtual IOperand const	*operator-(IOperand const & rhs) const = 0;
	virtual IOperand const	*operator*(IOperand const & rhs) const = 0;
	virtual IOperand const	*operator/(IOperand const & rhs) const = 0;
	virtual IOperand const	*operator%(IOperand const & rhs) const = 0;

	virtual std::string const & toString( void ) const  = 0; //string representation of the instance
};
#endif