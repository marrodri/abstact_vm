#ifndef OPERAND_FACTORY_HPP
#define OPERAND_FACTORY_HPP
#include "IOperand.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"
#include <limits.h>
#include <cmath>
class Operand_factory
{
private:

	IOperand const * createInt8(std::string const & value) const;
	IOperand const * createInt16(std::string const & value) const;
	IOperand const * createInt32(std::string const & value) const;
	IOperand const * createFloat(std::string const & value) const;
	IOperand const * createDouble(std::string const & value) const;
public:
	Operand_factory();
	Operand_factory(Operand_factory const & src);
	~Operand_factory();

	Operand_factory & operator=(Operand_factory const & rhs);

	IOperand const * createOperand(eOperandType type, std::string const & value) const;
};
#endif