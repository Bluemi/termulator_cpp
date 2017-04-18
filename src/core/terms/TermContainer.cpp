#include "TermContainer.hpp"

template <unsigned int NUM_OF_OPERATORS>
bool TermContainer<NUM_OF_OPERATORS>::validIndex(const unsigned int index) const
{
	return (index >= 0) && (index < NUM_OF_OPERATORS);
}

template <unsigned int NUM_OF_OPERATORS>
bool TermContainer<NUM_OF_OPERATORS>::isContainer() const
{
	return true;
}

template <unsigned int NUM_OF_OPERATORS>
bool TermContainer<NUM_OF_OPERATORS>::hasValue() const
{
	for (unsigned int i = 0; i < NUM_OF_OPERATORS; i++)
	{
		if ((getChild(i) == nullptr) || (!getChild(i)->hasValue()))
		{
			return false;
		}
	}
	return true;
}

template <unsigned int NUM_OF_OPERATORS>
std::string TermContainer<NUM_OF_OPERATORS>::getString() const
{
	std::string s = "";
	for (unsigned int i = 0; i < NUM_OF_OPERATORS; i++)
	{
		s += getChild(i)->getString();
		if (i != (NUM_OF_OPERATORS-1))
		{
			s += getLinkSign();
		}
	}
	return s;
}

template <unsigned int NUM_OF_OPERATORS>
TermContainer<NUM_OF_OPERATORS>::TermContainer()
{
	for (unsigned int i = 0; i < NUM_OF_OPERATORS; i++)
	{
		terms[i] = nullptr;
	}
}

template <unsigned int NUM_OF_OPERATORS>
Term* TermContainer<NUM_OF_OPERATORS>::getChild(const unsigned int index) const
{
	if (validIndex(index))
	{
		return terms[index];
	}
	return nullptr;
}

template <unsigned int NUM_OF_OPERATORS>
Term* TermContainer<NUM_OF_OPERATORS>::setChild(const unsigned int index, Term* t)
{
	if (validIndex(index))
	{
		Term* oldTerm = terms[index];
		terms[index] = t;
		return oldTerm;
	}
	return nullptr;
}

template class TermContainer<2>;
