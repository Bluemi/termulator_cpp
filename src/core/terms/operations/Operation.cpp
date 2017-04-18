#include "Operation.hpp"

template <unsigned int NUM_OF_OPERATORS>
Operation<NUM_OF_OPERATORS>::Operation()
{}

template <unsigned int NUM_OF_OPERATORS>
DataType Operation<NUM_OF_OPERATORS>::getValueType() const
{
	return DataType::DOUBLE;
}

template <unsigned int NUM_OF_OPERATORS>
bool Operation<NUM_OF_OPERATORS>::hasValue() const
{
	if (!TermContainer<NUM_OF_OPERATORS>::hasValue())
	{
		return false;
	}
	for (unsigned int i = 0; i < NUM_OF_OPERATORS; i++)
	{
		if (TermContainer<NUM_OF_OPERATORS>::getChild(i)->getValueType() != DataType::DOUBLE)
		{
			return false;
		}
	}
	return true;
}

template class Operation<2>;
