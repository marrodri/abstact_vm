
#include "Double.hpp" 
#include "Operand_factory.hpp"

Double::Double(long double value)
{	
	if (value > DBL_MAX)
	{
		throw Op_exceptions("overflow with the double operand");
	}
	else if (value < DBL_MIN)
	{
		throw Op_exceptions("underflow with the double operand");
	}
	else
	{
		this->double_val = value;
		this->instance = std::to_string(this->double_val);
	}
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
	Operand_factory factory;
	double first_val = std::stod(this->toString());
	double sec_val = std::stod(rhs.toString());
	std::string val_string = std::to_string(first_val + sec_val);

	if (this->getPrecision() >= rhs.getPrecision())
		return factory.createOperand(this->getType(), val_string);
	else
		return factory.createOperand(rhs.getType(), val_string);
}

IOperand const *Double::operator-(IOperand const & rhs) const
{
	Operand_factory factory;
	double first_val = std::stod(this->toString());
	double sec_val = std::stod(rhs.toString());
	std::string val_string = std::to_string(first_val - sec_val);

	if (this->getPrecision() >= rhs.getPrecision())
		return factory.createOperand(this->getType(), val_string);
	else
		return factory.createOperand(rhs.getType(), val_string);
}

IOperand const *Double::operator*(IOperand const & rhs) const
{
	Operand_factory factory;
	double first_val = std::stod(this->toString());
	double sec_val = std::stod(rhs.toString());
	std::string val_string = std::to_string(first_val * sec_val);

	if (this->getPrecision() >= rhs.getPrecision())
		return factory.createOperand(this->getType(), val_string);
	else
		return factory.createOperand(rhs.getType(), val_string);
}

//here set the exception when div is wih 0
IOperand const *Double::operator/(IOperand const & rhs) const
{
	return NULL;
}

//here set the exception when mod is wih 0
IOperand const *Double::operator%(IOperand const & rhs) const
{
	return NULL;
}


std::string const &Double::toString(void) const
{
	return (this->instance);
}