#ifndef INT16_HPP
#define INT16_HPP

#include "IOperand.hpp"

class Int16 : public IOperand
{
private:
	short int16;
public:
	Int16();
	Int16(Int16 const & src);
	~Int16();

	//get function
	//set function

};
#endif