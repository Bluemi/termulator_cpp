#include "Controller.hpp"

#include <core/system/System.hpp>

Controller::Controller()
	: target_(nullptr)
{
}

Controller::~Controller()
{
}

void Controller::setTarget(System* target)
{
	target_ = target;
}

bool Controller::hasTarget() const
{
	return (target_ != nullptr);
}

System* Controller::getTarget() const
{
	return target_;
}
