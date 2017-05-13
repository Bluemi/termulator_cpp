#ifndef __CONSOLE_CLASS__
#define __CONSOLE_CLASS__

#include <string>
#include <vector>

#include <editor/ui/Panel.hpp>
#include <editor/messages/Message.hpp>
#include <editor/console/commands/Command.hpp>

class Console : public Panel
{
	public:
		Console(int y);
		~Console();
		void applyChar(const char c);
		std::string getText() const;
		Message* pollMessage();
		bool hasMessage() const;

		virtual void subRender() override;

		static const char BACKSPACE = 7;
	private:
		void invokeCommand(Command* c);
		void applyCommand();

		std::string text_;
		std::vector<Message*> messages_;
		std::vector<Command*> commands_;
};

#endif
