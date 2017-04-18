#include "DataType.hpp"

#include <iostream>

std::string getTypeName(const DataType t)
{
	switch (t)
	{
		case DataType::BOOL:
		{
			return "BOOL";
		}
		case DataType::DOUBLE:
		{
			return "DOUBLE";
		}
		case DataType::INT:
		{
			return "INT";
		}
		case DataType::UNDEFINED:
		{
			return "UNDEFINED";
		}
	}
	std::cout << "Unknown DataType: " << t << std::endl;
	return "";
}

bool matches(const DataType& a, const DataType& b)
{
	if (a == DataType::UNDEFINED)
	{
		return false;
	}
	return (a == b);
}
