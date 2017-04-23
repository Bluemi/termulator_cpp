#include "System.hpp"

System::System()
	: TermContainer(NUM_OF_SYSTEM_CHILDS)
{}

Data System::getValue() const
{
	if (getRoot() == nullptr)
	{
		return Data();
	}
	if (!getRoot() ->hasValue())
	{
		return Data();
	}
	return getRoot()->getValue();
}

std::string System::getSystemString() const
{
	if (getRoot() == nullptr)
	{
		return "";
	}
	return getRoot()->getString();
}

DataType System::getValueType() const
{
	if (getRoot() == nullptr)
	{
		return DataType::UNDEFINED;
	}
	return getRoot()->getValueType();
}

std::string System::getLinkSign() const
{
	return "";
}

Term* System::getRoot() const
{
	return getChild(0);
}
