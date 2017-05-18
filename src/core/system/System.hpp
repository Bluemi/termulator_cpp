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
		bool containerSelected() const;

		// selection control
		void selectUp();
		void selectDown();
		void selectLeft();
		void selectRight();

		virtual Representation getRepresentation(Representable* markedRepresentable) const;
	private:
		Term* getLeaf() const;
		TermContainer* getLeafContainer();
		Term* getRoot() const;
		virtual bool replace(Term* victim, Term* replacement) override;
		void setRoot(Term* t);
		std::vector<Term*> branch_;
};

#endif
