#include "Operation.hpp"

Operation::Operation(const unsigned int size)
	: TermContainer(size)
{}

ValueType Operation::getValueType() const
{
	return ValueType::DOUBLE;
}

bool Operation::hasValue() const
{
	if (!TermContainer::hasValue())
	{
		return false;
	}
	for (unsigned int i = 0; i < getSize(); i++)
	{
		if (TermContainer::getChild(i)->getValueType() != ValueType::DOUBLE)
		{
			return false;
		}
	}
	return true;
}

Representation Operation::getRepresentation(Representable* markedRepresentable) const
{
	Representation rep;
	if (this == markedRepresentable)
	{
		rep.addMarkerBegin();
	}
	rep.add("(");
	for (unsigned int i = 0; i < getSize(); i++)
	{
		rep.add(getChild(i)->getRepresentation(markedRepresentable));
		if (i != (getSize()-1))
		{
			rep.add(getLinkSign());
		}
	}
	rep.add(")");
	if (this == markedRepresentable)
	{
		rep.addMarkerEnd();
	}
	return rep;
}
