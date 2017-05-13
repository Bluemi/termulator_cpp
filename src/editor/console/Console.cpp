#include "Console.hpp"

#include <editor/console/commands/QuitCommand.hpp>

Console::Console(int y)
	: Panel(y, 0, 1, COLS, Panel::RenderMode::CLEAR)
{
	// Commands
	commands_.push_back(new QuitCommand());
}

Console::~Console()
{
	for (Command* c : commands_)
	{
		delete c;
	}
	for (Message* m : messages_)
	{
		delete m;
	}
}

bool drawableSign(const char c)
{
	if ((c >= 32) && (c <= 126))
	{
		return true;
	}
	return false;
}

void Console::applyChar(const char c)
{
	if (drawableSign(c))
	{
		text_.push_back(c);
	}
	else if (c == BACKSPACE) // backspace
	{
		if (text_.size() > 0)
		{
			text_.pop_back();
		}
	}
	else if (c == 10) // Return
	{
		applyCommand();
	}
}

std::string Console::getText() const
{
	return text_;
}

Message* Console::pollMessage()
{
	if (hasMessage())
	{
		Message* tmp = messages_.back();
		messages_.pop_back();
		return tmp;
	}
	return nullptr;
}

bool Console::hasMessage() const
{
	return !messages_.empty();
}

void Console::subRender()
{
	waddstr(getWindow(), text_.c_str());
}

void Console::invokeCommand(Command* c)
{
	c->onAction();
	while (c->hasMessage())
	{
		messages_.push_back(c->pollMessage());
	}
}

void Console::applyCommand()
{
	for (Command* c : commands_)
	{
		if (text_.find(c->getName()) == 0)
		{
			invokeCommand(c);
			return;
		}
	}
	text_.clear();
}
