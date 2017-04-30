#include "ValueType.hpp"

#include <iostream>

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
	std::cout << "Unknown ValueType: " << t << std::endl;
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
