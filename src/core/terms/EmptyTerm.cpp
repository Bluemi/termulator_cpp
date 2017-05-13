#include "EmptyTerm.hpp"

EmptyTerm::EmptyTerm()
{}

EmptyTerm::~EmptyTerm()
{}

Value EmptyTerm::getValue() const
{
	return Value();
}

ValueType EmptyTerm::getValueType() const
{
	return ValueType::UNDEFINED;
}

bool EmptyTerm::hasValue() const
{
	return false;
}

std::string EmptyTerm::getString(Stringable* markedStringable) const
{
	if (markedStringable == this)
	{
		return "<_>";
	}
	return "_";
}

bool EmptyTerm::isEmptyTerm() const
{
	return true;
}
