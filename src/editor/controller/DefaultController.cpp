#include "DefaultController.hpp"

#include <core/system/System.hpp>
#include <core/terms/operations/Addition.hpp>
#include <core/misc/Debug.hpp>

DefaultController::DefaultController()
{}

DefaultController::~DefaultController()
{}

void DefaultController::applyKeyPress(const char c)
{
	if (!hasTarget())
	{
		Debug::out << Debug::warn << "DefaultController::applyKeyPress(): has no target" << Debug::endl;
	}
	switch (c)
	{
		case 'j':
		case 'J':
		{
			getTarget()->selectDown();
			break;
		}
		case 'k':
		case 'K':
		{
			getTarget()->selectUp();
			break;
		}
		case 'h':
		case 'H':
		{
			getTarget()->selectLeft();
			break;
		}
		case 'l':
		case 'L':
		{
			getTarget()->selectRight();
			break;
		}
		case '+':
		{
			getTarget()->addContainer(new Addition());
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
		{
			break;
		}
	}
}
