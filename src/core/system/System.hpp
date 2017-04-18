#ifndef __SYSTEM_CLASS__
#define __SYSTEM_CLASS__

#include <string>

#include <core/terms/Term.hpp>

class System
{
	public:
		System();
		// organisation
		void addTerm(Term* term);
		// getter
		Data getValue() const;
		std::string getSystemString() const;
	private:
		Term* root;
};

#endif
