#ifndef __OPERATION_CLASS__
#define __OPERATION_CLASS__

#include <core/terms/Term.hpp>
#include <core/terms/TermContainer.hpp>

template <unsigned int NUM_OF_OPERATORS>
class Operation : public Term<int>, public TermContainer<int, NUM_OF_OPERATORS>
{
	public:
		Operation();
};

#endif
