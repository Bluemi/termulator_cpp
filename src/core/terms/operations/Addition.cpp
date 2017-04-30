#include "Addition.hpp"

Addition::Addition()
	: Operation(2)
{}

Value Addition::getValue() const
{
	if (!hasValue())
	{
		return Value();
	}
	return Value(getChild(0)->getValue().get<double>() + getChild(1)->getValue().get<double>());
}

std::string Addition::getLinkSign() const
{
	return "+";
}
