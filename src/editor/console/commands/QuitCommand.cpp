#include "QuitCommand.hpp"

#include <editor/messages/QuitMessage.hpp>

QuitCommand::QuitCommand()
{}

QuitCommand::~QuitCommand()
{}

std::string QuitCommand::getName() const
{
	return "quit";
}

void QuitCommand::onAction()
{
	addMessage(new QuitMessage());
}
