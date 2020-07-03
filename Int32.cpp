
#include "Int32.hpp" 
#include "Operand_factory.hpp"
Int32::Int32(double value)
{
	if(value > INT_MAX)
	{
		throw Op_exceptions("overflow with the int32 operand");
	}
	else if(value < INT_MIN)
	{
		throw Op_exceptions("underflow with the int32 operand");
	}
	else
	{
		this->int32_val = value;
		this->instance = std::to_string(this->int32_val);
	}
}

Int32::Int32(Int32 const & src)
{
}

Int32::~Int32()
{
}

int Int32::getPrecision(void) const
{
	return (32);
}

eOperandType Int32::getType(void) const
{
	return (int32);
}

IOperand const *Int32::operator+(IOperand const & rhs) const
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

IOperand const *Int32::operator-(IOperand const & rhs) const
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

IOperand const *Int32::operator*(IOperand const & rhs) const
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

IOperand const *Int32::operator/(IOperand const & rhs) const
{
	Operand_factory factory;
	double first_val = std::stod(this->toString());
	double sec_val = std::stod(rhs.toString());
	std::string val_string = "";

	if (first_val == 0 || sec_val == 0)
	{
		delete this;
		delete &rhs;
		throw Op_exceptions("There is a division 0, cannot continue with the operation");
	}
	val_string = std::to_string(first_val / sec_val);
	if (this->getPrecision() >= rhs.getPrecision())
		return factory.createOperand(this->getType(), val_string);
	else
		return factory.createOperand(rhs.getType(), val_string);
}

IOperand const *Int32::operator%(IOperand const & rhs) const
{
	Operand_factory factory;
	double first_val = std::stod(this->toString());
	double sec_val = std::stod(rhs.toString());
	double remainder = 0;
	std::string val_string = "";

	if (first_val == 0 || sec_val == 0)
	{
		delete this;
		delete &rhs;
		throw Op_exceptions("There is a modulo by 0, cannot continue with the operation");
	}
	val_string = std::to_string(std::fmod(first_val, sec_val));
	if (this->getPrecision() >= rhs.getPrecision())
		return factory.createOperand(this->getType(), val_string);
	else
		return factory.createOperand(rhs.getType(), val_string);
}


std::string const &Int32::toString(void) const 
{
	return (this->instance);
}