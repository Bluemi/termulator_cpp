#ifndef __TERMCONTAINER_CLASS__
#define __TERMCONTAINER_CLASS__

#include "Term.hpp"

class TermContainer : public Term
{
	public:
		TermContainer(unsigned int size);
		virtual ~TermContainer();
		bool validIndex(const unsigned int index) const;
		virtual bool isContainer() const override;
		virtual bool hasValue() const override;
		virtual std::string getString() const override;
		unsigned int getChildSize() const;
		bool addChild(Term* t);
	protected:
		Term* getChild(const unsigned int index) const;
		Term* setChild(const unsigned int index, Term* t); // returns the term hold before at <index>
		virtual std::string getLinkSign() const = 0;
		bool isSlotEmpty(const unsigned int i) const;
		unsigned int getFirstEmptySlot() const;
	private:
		Term** terms_;
		unsigned int size_;
};

#endif
