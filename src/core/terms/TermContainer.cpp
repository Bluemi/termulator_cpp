#include "TermContainer.hpp"

template <typename T, unsigned int NUM_OF_OPERATORS>
bool TermContainer<T, NUM_OF_OPERATORS>::validIndex(const unsigned int index) const
{
	return (index >= 0) && (index < NUM_OF_OPERATORS);
}

template <typename T, unsigned int NUM_OF_OPERATORS>
TermContainer<T, NUM_OF_OPERATORS>::TermContainer()
{
	for (unsigned int i = 0; i < NUM_OF_OPERATORS; i++)
	{
		terms[i] = nullptr;
	}
}

template <typename T, unsigned int NUM_OF_OPERATORS>
Term<T>* TermContainer<T,NUM_OF_OPERATORS>::getChild(const unsigned int index) const
{
	if (validIndex(index))
	{
		return terms[index];
	}
	return nullptr;
}

template <typename T, unsigned int NUM_OF_OPERATORS>
Term<T>* TermContainer<T, NUM_OF_OPERATORS>::setChild(const unsigned int index, Term<T>* t)
{
	if (validIndex(index))
	{
		Term<T>* oldTerm = terms[index];
		terms[index] = t;
		return oldTerm;
	}
	return nullptr;
}

template class TermContainer<int, 2>;
