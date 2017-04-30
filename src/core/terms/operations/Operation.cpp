#include "Operation.hpp"

Operation::Operation(const unsigned int size)
	: TermContainer(size)
{}

ValueType Operation::getValueType() const
{
	return ValueType::DOUBLE;
}

bool Operation::hasValue() const
{
	if (!TermContainer::hasValue())
	{
		return false;
	}
	for (unsigned int i = 0; i < getChildSize(); i++)
	{
		if (TermContainer::getChild(i)->getValueType() != ValueType::DOUBLE)
		{
			return false;
		}
	}
	return true;
}
