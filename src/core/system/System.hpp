#ifndef __SYSTEM_CLASS__
#define __SYSTEM_CLASS__

#include <string>
#include <stack>

#include <core/terms/Term.hpp>
#include <core/terms/TermContainer.hpp>

constexpr unsigned int NUM_OF_SYSTEM_CHILDS = 1;

class System : public TermContainer
{
	public:
		System();
		~System();
		// getter
		Data getValue() const;
		std::string getSystemString() const;
		virtual DataType getValueType() const override;
		bool hasRoot() const;
	protected:
		virtual std::string getLinkSign() const override;
	private:
		Term* getRoot() const;
		std::stack<Term*> branch_;
};

#endif
