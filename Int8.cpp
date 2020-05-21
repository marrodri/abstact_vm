

#include "Int8.hpp" 

Int8::Int8(char value)
{
	this->int8 = value;
}

Int8::Int8()
{
	this->int8 = 0;
}

// IOperand const * Int8::createInt8(std::string const & value) const
// {
// 	char char_value = std::stoi(value);
// 	// char val;
	
// 	Int8 * test;
// 	test->setValue(char_value);
// 	// test
// 	return test;
// }

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
int IOperand::getPrecision(void) const{}
eOperandType IOperand::getType(void) const{}
IOperand const *IOperand::operator+(IOperand const & rhs) const{}
IOperand const *IOperand::operator-(IOperand const & rhs) const{}
IOperand const *IOperand::operator*(IOperand const & rhs) const{}
IOperand const *IOperand::operator/(IOperand const & rhs) const{}
IOperand const *IOperand::operator%(IOperand const & rhs) const{}