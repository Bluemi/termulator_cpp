#ifndef __TERM_CLASS__
#define __TERM_CLASS__

#include <string>

#include <core/values/Value.hpp>
#include <core/interfaces/Stringable.hpp>

class Term : public Stringable
{
	public:
		Term();
		virtual ~Term();
		// value
		virtual Value getValue() const = 0;
		virtual ValueType getValueType() const = 0;
		virtual bool hasValue() const = 0;
		// container
		virtual bool isContainer() const;
		virtual bool isEmptyTerm() const;
};

#endif
