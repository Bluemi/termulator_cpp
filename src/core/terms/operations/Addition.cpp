#include "Addition.hpp"

Addition::Addition()
{}

Data Addition::getValue() const
{
	if (!hasValue())
	{
		return Data();
	}
	return Data(getChild(0)->getValue().get<double>() + getChild(1)->getValue().get<double>());
}

std::string Addition::getLinkSign() const
{
	return "+";
}
