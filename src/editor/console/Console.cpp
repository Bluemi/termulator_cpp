#include "Console.hpp"

#include <core/misc/Debug.hpp>

Console::Console(int y)
	: Panel(3, 3, 5, 5, Panel::RenderMode::CLEAR)
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
	//size_t occurrence = text.find
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
	Debug::out << "Console::render()" << Debug::endl;
	Panel::render();
	Debug::out << "Console::addch" << Debug::endl;
	for (auto iter = text_.begin(); iter != text_.end(); ++iter)
		waddch(getWindow(), *iter);
	Panel::refresh();
}
