
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

IOperand const *Double::operator+(IOperand const & rhs) const
{
	std::cout <<  "setting sum short value" << std::endl;
	double first_val = std::stod(this->toString());
	double sec_val = std::stod(rhs.toString());
	return (new Double(first_val + sec_val));
}

IOperand const *Double::operator-(IOperand const & rhs) const{}
IOperand const *Double::operator*(IOperand const & rhs) const{}
IOperand const *Double::operator/(IOperand const & rhs) const{}
IOperand const *Double::operator%(IOperand const & rhs) const{}

std::string const &Double::toString(void) const
{
	return (this->instance);
}