#ifndef INT8_HPP
#define INT8_HPP

#include "IOperand.hpp"

class Int8 : public IOperand
{
private:
	char int8;
	//create attribute members here
public:
	Int8();
	// Int8(char value);
 
	IOperand const * createInt8(std::string const & value) const;

	//get function
	//set function

};
#endif