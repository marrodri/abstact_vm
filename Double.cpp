
#include "Double.hpp" 

Double::Double(double value)
{
	this->double_val = value;
	this->instance = std::to_string(this->double_val);
}

Double::Double(Double const & src)
{
}

Double::~Double()
{
}

int Double::getPrecision(void) const
{
	return (128);
}

eOperandType Double::getType(void) const
{
	return (double_class);
}

IOperand const *Double::operator+(IOperand const & rhs) const{}
IOperand const *Double::operator-(IOperand const & rhs) const{}
IOperand const *Double::operator*(IOperand const & rhs) const{}
IOperand const *Double::operator/(IOperand const & rhs) const{}
IOperand const *Double::operator%(IOperand const & rhs) const{}

std::string const &Double::toString(void) const
{
	return (this->instance);
}