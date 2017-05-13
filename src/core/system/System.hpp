#ifndef __SYSTEM_CLASS__
#define __SYSTEM_CLASS__

#include <vector>

#include <core/terms/Term.hpp>
#include <core/terms/TermContainer.hpp>

class System : public TermContainer
{
	public:
		System();
		~System();
		// getter
		Value getValue() const;
		virtual std::string getString() const override;
		ValueType getValueType() const;
		bool isEmpty() const;
		Term* getTop() const;
		TermContainer* getLeafContainer();
		void addContainer(TermContainer* c);
		bool addChild(Term* t);
		virtual std::string getLinkSign() const override;
		virtual bool replace(Term* victim, Term* replacement) override;

		void selectUp();
		void selectDown();
	private:
		Term* getRoot() const;
		void setRoot(Term* t);
		std::vector<Term*> branch_;
};

#endif
