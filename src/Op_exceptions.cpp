
#include "Op_exceptions.hpp" 

Op_exceptions::Op_exceptions(const std::string & msg)
{
	this->_msg = msg;
}

Op_exceptions::Op_exceptions(Op_exceptions const & src)
{
}

Op_exceptions::~Op_exceptions()
{
}

const char *Op_exceptions::what() const noexcept
{
	return this->_msg.c_str();
}
