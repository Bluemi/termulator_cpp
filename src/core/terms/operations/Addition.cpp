#include "Addition.hpp"

Addition::Addition()
{}

int Addition::getValue() const
{
	int sum = 0;
	Term<int>* a = getChild(0);
	if (a != nullptr)
	{
		sum = a->getValue();
	}
	a = getChild(1);
	if (a != nullptr)
	{
		sum += a->getValue();
	}
	return sum;
}
