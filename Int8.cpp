

#include "Int8.hpp" 

Int8::Int8(char value)
{
	this->int8 = value;
}

Int8::Int8()
{
	this->int8 = 0;
}

void Int8::setValue(char value)
{
	this->int8 = value;
}

char const Int8::getValue()
{
	return this->int8;
}

//check how to override
//THIS HAS ALL THE OPERAND CLASSES
int Int8::getPrecision(void) const{}
eOperandType Int8::getType(void) const{}
IOperand const *Int8::operator+(IOperand const & rhs) const{}
IOperand const *Int8::operator-(IOperand const & rhs) const{}
IOperand const *Int8::operator*(IOperand const & rhs) const{}
IOperand const *Int8::operator/(IOperand const & rhs) const{}
IOperand const *Int8::operator%(IOperand const & rhs) const{}

std::string const &Int8::toString(void) const 
{
	return NULL;
}