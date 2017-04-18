#ifndef __TERMCONTAINER_CLASS__
#define __TERMCONTAINER_CLASS__

#include "Term.hpp"

template <unsigned int NUM_OF_OPERATORS>
class TermContainer : public Term
{
	public:
		bool validIndex(const unsigned int index) const;
		virtual bool isContainer() const override;
		virtual bool hasValue() const override;
		virtual std::string getString() const override;
	protected:
		TermContainer();
		Term* getChild(const unsigned int index) const;
		Term* setChild(const unsigned int index, Term* t); // returns the term hold before at <index>
		virtual std::string getLinkSign() const = 0;
	private:
		Term* terms[NUM_OF_OPERATORS];
};

#endif
