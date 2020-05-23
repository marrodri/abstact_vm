

#include "Int8.hpp" 

Int8::Int8(char value)
{
	this->int8_val = value;
}

Int8::Int8()
{
	this->int8_val = 0;
}

void Int8::setValue(char value)
{
	this->int8_val = value;
}

char const Int8::getValue()
{
	return this->int8_val;
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

	std::string output = std::to_string((int)this->int8_val);
	return output;
}