#ifndef __TERM_CLASS__
#define __TERM_CLASS__

#include <core/data/Data.hpp>

class Term
{
	public:
		Term();
		virtual Data getValue() const = 0;
		virtual bool isContainer() const;
};

#endif
