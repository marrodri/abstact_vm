#ifndef INT16_HPP
#define INT16_HPP
#include "IOperand.hpp"
#include "Op_exceptions.hpp"

class Int16 : public IOperand
{
private:
	short int16_val;
	std::string instance;
public:
	Int16();
	Int16(double value);
	Int16(Int16 const & src);
	~Int16();


	char const getValue();
	void setValue(char value);

	int	getPrecision(void) const override; 
	eOperandType getType(void) const override;
	IOperand const *operator+(IOperand const & rhs) const override;
	IOperand const *operator-(IOperand const & rhs) const override;
	IOperand const *operator*(IOperand const & rhs) const override;
	IOperand const *operator/(IOperand const & rhs) const override;
	IOperand const *operator%(IOperand const & rhs) const override;
	std::string const &toString(void) const override;

};
#endif