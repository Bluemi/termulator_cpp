#ifndef __OPERATION_CLASS__
#define __OPERATION_CLASS__

/*
	super class of all arithmetic Operations like +, -. *, / ...
	has returnType DOUBLE
*/

#include <core/terms/TermContainer.hpp>

class Operation : public TermContainer
{
	public:
		Operation(const unsigned int size);
		// returns DataType::DOUBLE
		virtual DataType getValueType() const override;
		// returns true, if all Childs exist, have Value and this Value has to be of Type DOUBLE
		virtual bool hasValue() const override;
};

#endif
