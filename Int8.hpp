#ifndef INT8_HPP
#define INT8_HPP

#include "IOperand.hpp"
#include <string>
#include <iostream>
class Int8 : public IOperand
{
private:
	char int8_val;
	std::string instance;
	//create attribute members here
public:
	Int8();
	Int8(double value);
 
	// IOperand const * createInt8(std::string const & value) const;

	char const getValue();
	void setValue(char value);

	//override functions from the IOperands
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