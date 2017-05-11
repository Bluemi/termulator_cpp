#include "Command.hpp"

#include <core/misc/Debug.hpp>

Command::Command()
{}

Command::~Command()
{}

Message* Command::pollMessage()
{
	if (messages_.empty())
	{
		return nullptr;
	}
	Message* m = messages_.back();
	messages_.pop_back();
	return m;
}

void Command::addMessage(Message* m)
{
	if (m == nullptr)
	{
		Debug::out << Debug::error << "Command::addMessage(): m == nullptr" << Debug::endl;
		return;
	}
	messages_.push_back(m);
}
