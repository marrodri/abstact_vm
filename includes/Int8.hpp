#ifndef INT8_HPP
#define INT8_HPP

#include "IOperand.hpp"
#include "Op_exceptions.hpp"
#include <string>
#include <iostream>
class Int8 : public IOperand
{
private:
	char int8_val;
	std::string instance;
public:
	Int8();
	Int8(double value);

	int	getPrecision(void) const override; 
	eOperandType getType(void) const override;
	IOperand const *operator+(IOperand const & rhs) const override;
	IOperand const *operator-(IOperand const & rhs) const override;
	IOperand const *operator*(IOperand const & rhs) const override;
	IOperand const *operator/(IOperand const & rhs) const override;
	IOperand const *operator%(IOperand const & rhs) const override;
	std::string const &toString(void) const override;
};
#endif