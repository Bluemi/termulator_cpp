#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include <string>
#include <vector>

#include <editor/messages/Message.hpp>

class Command
{
	public:
		Command();
		virtual ~Command();
		virtual std::string getName() const = 0;
		virtual void onAction() = 0;
		Message* pollMessage();
		bool hasMessage() const;
	protected:
		void addMessage(Message*);
	private:
		std::vector<Message*> messages_;
};

#endif
