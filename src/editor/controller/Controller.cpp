#include "Controller.hpp"

#include <editor/ui/SystemTextBox.hpp>

Controller::Controller()
	: target_(nullptr)
{}

Controller::~Controller()
{}

void Controller::setTarget(SystemTextBox* target)
{
	target_ = target;
}

bool Controller::hasTarget() const
{
	return (target_ != nullptr);
}

SystemTextBox* Controller::getTarget() const
{
	return target_;
}
