#ifndef __STRINGABLE_CLASS__
#define __STRINGABLE_CLASS__

#include <string>

class Stringable
{
	public:
		Stringable();
		virtual ~Stringable();
		virtual std::string getString(Stringable* markedStringable = nullptr) const = 0;
};

#endif
