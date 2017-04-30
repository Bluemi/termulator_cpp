#ifndef __TERM_CLASS__
#define __TERM_CLASS__

#include <string>

#include <core/values/Value.hpp>

class Term
{
	public:
		Term();
		virtual ~Term();
		// value
		virtual Value getValue() const = 0;
		virtual ValueType getValueType() const = 0;
		virtual bool hasValue() const = 0;
		// string
		virtual std::string getString() const = 0;
		// container
		virtual bool isContainer() const;
		virtual bool isEmptyTerm() const;
};

#endif
