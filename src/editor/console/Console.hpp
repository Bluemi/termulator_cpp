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
		void applyChar(const char c);
		void applyCommand();
		std::string getText() const;
		Message* pollMessage();
		bool hasMessage() const;

		virtual void render() override;

		static const char BACKSPACE = 7;
	private:
		std::string text_;
		std::vector<Message*> messages;
		std::vector<Command*> commands_;
};

#endif
