#ifndef __SYSTEM_CLASS__
#define __SYSTEM_CLASS__

#include <vector>

#include <core/terms/Term.hpp>
#include <core/terms/TermContainer.hpp>

class System : private TermContainer
{
	public:
		System();
		~System();
		// getter
		Value getValue() const;
		ValueType getValueType() const;
		bool isEmpty() const;
		void addContainer(TermContainer* c);
		bool addChild(Term* t);
		std::string getSystemString(bool withMarker = true) const;

		// move control
		void selectUp();
		void selectDown();
		void selectLeft();
		void selectRight();
	private:
		virtual std::string getString(Stringable* markedStringable = nullptr) const override;
		Term* getLeaf() const;
		TermContainer* getLeafContainer();
		Term* getRoot() const;
		virtual std::string getLinkSign() const override;
		virtual bool replace(Term* victim, Term* replacement) override;
		void setRoot(Term* t);
		std::vector<Term*> branch_;
};

#endif
