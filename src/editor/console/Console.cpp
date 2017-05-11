#include "Console.hpp"

Console::Console(int y)
	: Panel(y, 0, 1, COLS, Panel::RenderMode::CLEAR)
{}

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

void Console::applyCommand()
{
	for (Command* c : commands_)
	{
		if (text_.find(c->getName()) == 0)
		{
			c->onAction();
		}
	}
	text_.clear();
}

std::string Console::getText() const
{
	return text_;
}

Message* Console::pollMessage()
{
	if (hasMessage())
	{
		Message* tmp = messages.back();
		messages.pop_back();
		return tmp;
	}
	return nullptr;
}

bool Console::hasMessage() const
{
	return !messages.empty();
}

void Console::render()
{
	Panel::render();
	for (auto iter = text_.begin(); iter != text_.end(); ++iter)
		waddch(getWindow(), *iter);
	Panel::refresh();
}
