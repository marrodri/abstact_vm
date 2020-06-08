
#include "Int16.hpp" 
#include "Operand_factory.hpp"
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
	Operand_factory factory;
	double first_val = std::stod(this->toString());
	double sec_val = std::stod(rhs.toString());
	std::string val_string = std::to_string(first_val + sec_val);

	if(this->getPrecision() >= rhs.getPrecision())
	{

		return factory.createOperand(this->getType(), val_string);
	}
	else
	{
		return factory.createOperand(rhs.getType(), val_string);
	}
}

IOperand const *Int16::operator-(IOperand const & rhs) const
{
	Operand_factory factory;
	double first_val = std::stod(this->toString());
	double sec_val = std::stod(rhs.toString());
	std::string val_string = std::to_string(first_val - sec_val);

	if(this->getPrecision() >= rhs.getPrecision())
		return factory.createOperand(this->getType(), val_string);
	else
		return factory.createOperand(rhs.getType(), val_string);
}

IOperand const *Int16::operator*(IOperand const & rhs) const
{
	Operand_factory factory;
	double first_val = std::stod(this->toString());
	double sec_val = std::stod(rhs.toString());
	std::string val_string = std::to_string(first_val * sec_val);

	if(this->getPrecision() >= rhs.getPrecision())
		return factory.createOperand(this->getType(), val_string);
	else
		return factory.createOperand(rhs.getType(), val_string);
}

IOperand const *Int16::operator/(IOperand const & rhs) const
{
	return NULL;
}

IOperand const *Int16::operator%(IOperand const & rhs) const
{
	return NULL;
}


std::string const &Int16::toString(void) const
{
	return (this->instance);
} 