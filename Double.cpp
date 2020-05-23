
#include "Double.hpp" 

Double::Double(/* args */)
{
}

Double::Double(double value)
{
	this->double_val = value;
}

Double::Double(Double const & src)
{
}

Double::~Double()
{
}

int Double::getPrecision(void) const{}
eOperandType Double::getType(void) const{}
IOperand const *Double::operator+(IOperand const & rhs) const{}
IOperand const *Double::operator-(IOperand const & rhs) const{}
IOperand const *Double::operator*(IOperand const & rhs) const{}
IOperand const *Double::operator/(IOperand const & rhs) const{}
IOperand const *Double::operator%(IOperand const & rhs) const{}
std::string const &Double::toString(void) const {return NULL;}