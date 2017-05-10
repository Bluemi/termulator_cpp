#include "DefaultController.hpp"

#include <core/system/System.hpp>

DefaultController::DefaultController()
{}

DefaultController::~DefaultController()
{}

void DefaultController::applyKeyPress(const char c)
{
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
	}
}
