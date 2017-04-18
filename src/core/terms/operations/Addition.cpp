#include "Addition.hpp"

Addition::Addition()
{}

Data Addition::getValue() const
{
	Term* a = getChild(0);
	Term* b = getChild(1);
	if ((a == nullptr) || (b == nullptr))
	{
		return Data();
	}
	return Data(a->getValue().get<double>() + b->getValue().get<double>());
}
