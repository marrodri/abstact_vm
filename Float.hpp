#ifndef FLOAT_HPP
#define FLOAT_HPP

#include "IOperand.hpp"
#include <float.h>
class Float : public IOperand
{
private:
	float float_val;
	std::string instance;
public:
	Float();
	Float(double value);
	Float(Float const & src);
	~Float();

	//get function
	//set function
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