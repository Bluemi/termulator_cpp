#include "IntNumber.hpp"

IntNumber::IntNumber(const int value)
	: value_(value)
{}

int IntNumber::getValue() const
{
	return value_;
}
