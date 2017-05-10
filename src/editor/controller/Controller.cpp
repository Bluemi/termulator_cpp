#include "Controller.hpp"

#include <core/system/System.hpp>

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::setTarget(System* target)
{
	if (target != nullptr)
	{
		target_ = target;
	}
}

System* Controller::getTarget() const
{
	return target_;
}
