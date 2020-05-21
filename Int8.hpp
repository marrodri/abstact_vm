#ifndef INT8_HPP
#define INT8_HPP

#include "IOperand.hpp"
#include <string>
#include <iostream>
class Int8 : public IOperand
{
private:
	char int8;
	//create attribute members here
public:
	Int8();
	Int8(char value);
 
	// IOperand const * createInt8(std::string const & value) const;


	char const getValue();
	void setValue(char value);
};
#endif