#ifndef __MESSAGE_CLASS__
#define __MESSAGE_CLASS__

class Editor;

class Message
{
	public:
		Message();
		virtual ~Message();
		virtual void dispatch(Editor* e) = 0;
};

#endif
