#ifndef __SYSTEM_CLASS__
#define __SYSTEM_CLASS__

#include <string>
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
		std::string getSystemString() const;
		ValueType getValueType() const;
		bool isEmpty() const;
		Term* getTop() const;
		TermContainer* getLeafContainer();
		void addContainer(TermContainer* c);
		bool addChild(Term* t);
		std::string getString() const;
		virtual std::string getLinkSign() const override;
		virtual bool replace(Term* victim, Term* replacement) override;
	private:
		Term* getRoot() const;
		void setRoot(Term* t);
		std::vector<Term*> branch_;
};

#endif
