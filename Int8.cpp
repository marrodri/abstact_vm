

#include "Int8.hpp" 

Int8::Int8(char value)
{
	// this->int8_val = value;
	this->int8_val = (int)value;
	int inst = value;
	this->instance = std::to_string(inst);	
}

void Int8::setValue(char value){}
int Int8::getPrecision(void) const
{
	return (8);
}

eOperandType Int8::getType(void) const
{
	return (int8);
}

IOperand const *Int8::operator+(IOperand const & rhs) const{}
IOperand const *Int8::operator-(IOperand const & rhs) const{}
IOperand const *Int8::operator*(IOperand const & rhs) const{}
IOperand const *Int8::operator/(IOperand const & rhs) const{}
IOperand const *Int8::operator%(IOperand const & rhs) const{}

std::string const &Int8::toString(void) const 
{
	return (this->instance);
}