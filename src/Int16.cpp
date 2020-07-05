
#include "Int16.hpp" 
#include "Operand_factory.hpp"

Int16::Int16(double value)
{
	if(value > SHRT_MAX)
	{
		throw Op_exceptions("overflow with the int16 operand");
	}
	else if(value < SHRT_MIN)
	{
		throw Op_exceptions("underflow with the int16 operand");
	}
	else
	{
		this->int16_val = value;
		this->instance = std::to_string(this->int16_val);
	}
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

IOperand const *Int16::operator%(IOperand const & rhs) const
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


std::string const &Int16::toString(void) const
{
	return (this->instance);
} 