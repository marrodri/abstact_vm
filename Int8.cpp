

#include "Int8.hpp" 

// Int8::Int8(char value)
// {
// 	this->int8 = value;
// }

Int8::Int8()
{
	this->int8 = 0;
}



IOperand const * Int8::createInt8(std::string const & value) const
{
	// return new Int8();
}

//check how to override
int IOperand::getPrecision(void) const{}
eOperandType IOperand::getType(void) const{}
IOperand const *IOperand::operator+(IOperand const & rhs) const{}
IOperand const *IOperand::operator-(IOperand const & rhs) const{}
IOperand const *IOperand::operator*(IOperand const & rhs) const{}
IOperand const *IOperand::operator/(IOperand const & rhs) const{}
IOperand const *IOperand::operator%(IOperand const & rhs) const{}