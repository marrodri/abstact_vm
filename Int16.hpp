#ifndef INT16_HPP
#define INT16_HPP

#include "IOperand.hpp"

class Int16 : public IOperand
{
private:
	short int16;
public:
	Int16();
	Int16(short value);
	Int16(Int16 const & src);
	~Int16();


	//get function
	char const getValue();
	//set function
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