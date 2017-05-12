#include "QuitMessage.hpp"

#include <editor/Editor.hpp>

QuitMessage::QuitMessage()
{}

QuitMessage::~QuitMessage()
{}

void QuitMessage::dispatch(Editor* e)
{
	e->applyQuitMessage(*this);
}
