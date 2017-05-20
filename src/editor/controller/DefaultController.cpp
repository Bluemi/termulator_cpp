#include "DefaultController.hpp"

#include <core/system/System.hpp>
#include <core/terms/operations/Addition.hpp>
#include <core/misc/Debug.hpp>
#include <editor/ui/SystemTextBox.hpp>

DefaultController::DefaultController()
{}

DefaultController::~DefaultController()
{}

void DefaultController::applyKeyPress(const char c)
{
	if (!hasTarget())
	{
		Debug::out << Debug::warn << "DefaultController::applyKeyPress(): has no target" << Debug::endl;
		return;
	}
	if (getTarget()->getSystem() == nullptr)
	{
		Debug::out << Debug::warn << "DefaultController::applyKeyPress(): target has no system" << Debug::endl;
		return;
	}
	switch (c)
	{
		case 'j':
		{
			getTarget()->finishInsertion();
			getTarget()->getSystem()->selectDown();
			break;
		}
		case 'k':
		{
			getTarget()->finishInsertion();
			getTarget()->getSystem()->selectUp();
			break;
		}
		case 'h':
		{
			getTarget()->finishInsertion();
			getTarget()->getSystem()->selectLeft();
			break;
		}
		case 'l':
		{
			getTarget()->finishInsertion();
			getTarget()->getSystem()->selectRight();
			break;
		}
		case '+':
		{
			getTarget()->finishInsertion();
			getTarget()->getSystem()->addContainer(new Addition());
			break;
		}
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '.':
		case ',':
		case '-':
		{
			getTarget()->insertChar(c);
			break;
		}
	}
}
