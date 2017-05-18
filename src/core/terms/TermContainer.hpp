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
		unsigned int getSize() const;
		bool addChild(Term* t);
		virtual bool replace(Term* victim, Term* replacement);
		virtual Term* getLefterChild(Term* t) const;
		virtual Term* getRighterChild(Term* t) const;
		bool isEmpty() const;
		const std::string MISSING_ARGUMENT;
		Term* getChild(const unsigned int index) const;
	protected:
		Term* setChild(const unsigned int index, Term* t); // returns the term hold before at <index>
		bool isSlotEmpty(const unsigned int i) const;
		unsigned int getFirstEmptySlot() const;
	private:
		Term** terms_;
		unsigned int size_;
};

#endif
