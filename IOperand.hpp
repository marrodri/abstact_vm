#ifndef IOPERAND_HPP
#define IOPERAND_HPP
#include <string>
#include <iostream>


/*
** this class gets inherited by all other operands,
** so all operands classes become IOperands.
*/

//ask if it should be a plain type or a class type for the enum
enum eOperandType
{
	Double
	// Int8, Int16, Int32, Float, Double
};

class IOperand {
public:
	virtual	~IOperand( void ) {};

	//virtual functions for the operand classes
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