
#include "Int16.hpp" 

Int16::Int16(short value)
{
	this->int16_val = value;
	this->instance = std::to_string(this->int16_val);
}

Int16::Int16(Int16 const & src)
{
}

Int16::~Int16()
{
}

int Int16::getPrecision(void) const
{
	return (16);
}

eOperandType Int16::getType(void) const
{
	return (int16);
}

IOperand const *Int16::operator+(IOperand const & rhs) const
{
	std::cout <<  "setting sum short value" << std::endl;
	double first_val = std::stod(this->toString());
	double sec_val = std::stod(rhs.toString());
	return (new Int16((short) first_val + sec_val));
}

IOperand const *Int16::operator-(IOperand const & rhs) const{return NULL;}
IOperand const *Int16::operator*(IOperand const & rhs) const{return NULL;}
IOperand const *Int16::operator/(IOperand const & rhs) const{return NULL;}
IOperand const *Int16::operator%(IOperand const & rhs) const{return NULL;}

std::string const &Int16::toString(void) const
{
	return (this->instance);
} 