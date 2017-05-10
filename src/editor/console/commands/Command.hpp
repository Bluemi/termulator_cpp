#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include <string>

class Command
{
	public:
		Command();
		virtual ~Command();
		virtual std::string getName() const = 0;
	private:
};

#endif
