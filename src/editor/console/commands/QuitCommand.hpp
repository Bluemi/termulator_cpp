#ifndef __QUITCOMMAND_CLASS__
#define __QUITCOMMAND_CLASS__

#include "Command.hpp"

class QuitCommand : public Command
{
	public:
		QuitCommand();
		virtual ~QuitCommand();
		virtual void onAction() override;
};

#endif
