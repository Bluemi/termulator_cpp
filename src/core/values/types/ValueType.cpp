#include "ValueType.hpp"

#include <core/misc/Debug.hpp>

std::string getTypeName(const ValueType t)
{
	switch (t)
	{
		case ValueType::BOOL:
		{
			return "BOOL";
		}
		case ValueType::DOUBLE:
		{
			return "DOUBLE";
		}
		case ValueType::INT:
		{
			return "INT";
		}
		case ValueType::UNDEFINED:
		{
			return "UNDEFINED";
		}
	}
	Debug::out << Debug::warn << "Unknown ValueType: " << t << Debug::endl;
	return "";
}

bool matches(const ValueType& a, const ValueType& b)
{
	if (a == ValueType::UNDEFINED)
	{
		return false;
	}
	return (a == b);
}
