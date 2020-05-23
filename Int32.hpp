#ifndef INT32_HPP
#define INT32_HPP
#include "IOperand.hpp"

class Int32 : public IOperand
{
private:
	int int32_val;
	std::string instance;
public:
	Int32();
	Int32(int value);
	Int32(Int32 const & src);
	~Int32();

	//get function
	//set function
	// char const getValue();
	// void setValue(char value);

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