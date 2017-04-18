#ifndef __TERM_CLASS__
#define __TERM_CLASS__

#include <string>

#include <core/data/Data.hpp>

class Term
{
	public:
		Term();
		// value
		virtual Data getValue() const = 0;
		virtual DataType getValueType() const = 0;
		virtual bool hasValue() const = 0;
		// string
		virtual std::string getString() const = 0;
		// container
		virtual bool isContainer() const;
};

#endif
