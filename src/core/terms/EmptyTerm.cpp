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

Representation EmptyTerm::getRepresentation(Representable* markedRepresentable) const
{
	Representation rep;
	if (this == markedRepresentable)
	{
		rep.addMarkerBegin();
		rep.add("_");
		rep.addMarkerEnd();
	}
	else
	{
		rep.add("_");
	}
	return rep;
}

bool EmptyTerm::isEmptyTerm() const
{
	return true;
}
