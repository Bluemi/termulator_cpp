#include "QuitCommand.hpp"

#include <editor/messages/QuitMessage.hpp>

QuitCommand::QuitCommand()
{}

QuitCommand::~QuitCommand()
{}

void QuitCommand::onAction()
{
	addMessage(new QuitMessage());
}
