#ifndef __OPERATION_CLASS__
#define __OPERATION_CLASS__

#include <core/terms/TermContainer.hpp>

template <unsigned int NUM_OF_OPERATORS>
class Operation : public TermContainer<NUM_OF_OPERATORS>
{
	public:
		Operation();
};

#endif
