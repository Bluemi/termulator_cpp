#include "Operation.hpp"

Operation::Operation(const unsigned int size)
	: TermContainer(size)
{}

DataType Operation::getValueType() const
{
	return DataType::DOUBLE;
}

bool Operation::hasValue() const
{
	if (!TermContainer::hasValue())
	{
		return false;
	}
	for (unsigned int i = 0; i < getChildSize(); i++)
	{
		if (TermContainer::getChild(i)->getValueType() != DataType::DOUBLE)
		{
			return false;
		}
	}
	return true;
}
