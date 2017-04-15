#include "Value.hpp"

#include <iostream>
#include <tgmath.h>

Value::Value(const Value::Behavior behavior)
	: behavior_(behavior), coefficient_(0), exponent_(0)
{}

Value::~Value()
{}

// Approx
double Value::getApprox() const
{
	return coefficient_ * pow(10.0, exponent_);
}

void Value::setApprox(const double value)
{
	std::cout << "Value::setApprox(): TODO" << std::endl;
}

std::string Value::getString() const
{
	std::cout << "Value::getString(): TODO" << std::endl;
	return "";
}

// parse
bool parseInt(const std::string& s)
{
	std::cout << "Value::parseInt(): TODO" << std::endl;
	return false;
}

bool Value::parseFloat(const std::string& s)
{
	std::cout << "Value::parseInt(): TODO" << std::endl;
	return false;
}

// Behavior
Value::Behavior Value::getBehavior() const
{
	return behavior_;
}

void Value::setBehavior(const Value::Behavior behavior)
{
	behavior_ = behavior;
}

// operations
Value Value::operator+(const Value& value) const
{
	std::cout << "Value::operator+(): TODO" << std::endl;
	return Value(INT_BEHAVIOR);
}

Value Value::operator-(const Value& value) const
{
	std::cout << "Value::operator+(): TODO" << std::endl;
	return Value(INT_BEHAVIOR);
}

Value Value::operator*(const Value& value) const
{
	std::cout << "Value::operator+(): TODO" << std::endl;
	return Value(INT_BEHAVIOR);
}

Value Value::operator/(const Value& value) const
{
	std::cout << "Value::operator+(): TODO" << std::endl;
	return Value(INT_BEHAVIOR);
}

bool Value::operator==(const Value& value) const
{
	std::cout << "Value::operator+(): TODO" << std::endl;
	return false;
}
