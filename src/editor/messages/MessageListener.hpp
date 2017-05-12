#ifndef __MESSAGELISTENER_CLASS__
#define __MESSAGELISTENER_CLASS__

#include "QuitMessage.hpp"

class MessageListener
{
	public:
		MessageListener();
		virtual ~MessageListener();
		virtual void applyQuitMessage(const QuitMessage& m) = 0;
};

#endif
