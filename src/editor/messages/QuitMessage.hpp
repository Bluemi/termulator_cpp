#ifndef __QUITMESSAGE_CLASS__
#define __QUITMESSAGE_CLASS__

#include "Message.hpp"

class QuitMessage : public Message
{
	public:
		QuitMessage();
		virtual ~QuitMessage();
		virtual void dispatch(Editor* e) override;
};

#endif
