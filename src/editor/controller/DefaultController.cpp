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
			if (hasTarget())
			{
				getTarget()->selectDown();
			}
			break;
		}
		case 'k':
		case 'K':
		{
			if (hasTarget())
			{
				getTarget()->selectUp();
			}
			break;
		}
	}
}
