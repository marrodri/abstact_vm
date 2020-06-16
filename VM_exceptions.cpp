
#include "VM_exceptions.hpp" 

VM_exceptions::VM_exceptions(const std::string & msg)
{
	this->_msg = msg;
}

VM_exceptions::VM_exceptions(VM_exceptions const & src)
{
}

VM_exceptions::~VM_exceptions()
{
}


const char *VM_exceptions::what() const noexcept 
{
	return this->_msg.c_str();
}


