#ifndef __TERMCONTAINER_CLASS__
#define __TERMCONTAINER_CLASS__

#include "Term.hpp"

template <typename T, unsigned int NUM_OF_OPERATORS>
class TermContainer
{
	public:
		bool validIndex(const unsigned int index) const;
	protected:
		TermContainer();
		Term<T>* getChild(const unsigned int index) const;
		Term<T>* setChild(const unsigned int index, Term<T>* t); // returns the term hold before at <index>
	private:
		Term<T>* terms[NUM_OF_OPERATORS];
};

#endif
