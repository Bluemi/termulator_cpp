#ifndef __OPERATION_CLASS__
#define __OPERATION_CLASS__

/*
	super class of all arithmetic Operations like +, -. *, / ...
	has returnType DOUBLE
*/

#include <core/terms/TermContainer.hpp>

template <unsigned int NUM_OF_OPERATORS>
class Operation : public TermContainer<NUM_OF_OPERATORS>
{
	public:
		Operation();
		// returns DataType::DOUBLE
		virtual DataType getValueType() const override;
		// returns true, if all Childs exist, have Value and this Value has to be of Type DOUBLE
		virtual bool hasValue() const override;
};

#endif
