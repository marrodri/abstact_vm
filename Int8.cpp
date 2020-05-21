

#include "Int8.hpp" 

Int8::Int8(char value)
{
	this->int8 = value;
}

//check how to override
int IOperand::getPrecision(void) const{}
eOperandType IOperand::getType(void) const{}
IOperand const *IOperand::operator+(IOperand const & rhs) const{}
IOperand const *IOperand::operator-(IOperand const & rhs) const{}
IOperand const *IOperand::operator*(IOperand const & rhs) const{}
IOperand const *IOperand::operator/(IOperand const & rhs) const{}
IOperand const *IOperand::operator%(IOperand const & rhs) const{}