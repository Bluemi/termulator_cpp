#ifndef __EMPTYTERM_CLASS__
#define __EMPTYTERM_CLASS__

#include "Term.hpp"

class EmptyTerm : public Term
{
	public:
		EmptyTerm();
		virtual ~EmptyTerm();
		virtual Data getValue() const override;
		virtual DataType getValueType() const override;
		virtual bool hasValue() const override;
		virtual std::string getString() const override;
		virtual bool isEmptyTerm() const override;
};

#endif
