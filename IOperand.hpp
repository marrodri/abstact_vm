#ifndef IOPERAND_H
#define IOPERAND_H
#include <string>
#include <iostream>

//probably you should move it to it's .cpp file
enum class eOperandType
{
	Int8, Int16, Int32, Float, Double
};

class IOperand {

private:
	//use a switch case
	//CreateOperand(class of the operand, input string the value int);
	IOperand const * createOperand(eOperandType type, std::string const & value) const;

	//each function will create a class with the value added, and
	//pushed right away into the stack
	IOperand const * createInt8(std::string const & value) const;
	IOperand const * createInt16(std::string const & value) const;
	IOperand const * createInt32(std::string const & value) const;
	IOperand const * createFloat(std::string const & value) const;
	IOperand const * createDouble(std::string const & value) const;

public:
	virtual int				getPrecision( void ) const = 0; //precision of the type of the instance
	virtual eOperandType	getType(void) const = 0; //type of the instance
	//ask if it should be a plain type or a class type for the enum
	virtual IOperand const	*operator+(IOperand const & rhs) const = 0;
	virtual IOperand const	*operator-(IOperand const & rhs) const = 0;
	virtual IOperand const	*operator*(IOperand const & rhs) const = 0;
	virtual IOperand const	*operator/(IOperand const & rhs) const = 0;
	virtual IOperand const	*operator%(IOperand const & rhs) const = 0;

	virtual std::string const & toString( void ) const  = 0; //string representation of the instance
	
	virtual	~IOperand( void ) {};
};
#endif