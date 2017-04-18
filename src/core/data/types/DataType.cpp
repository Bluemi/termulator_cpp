#include "DataType.hpp"

#include <iostream>

std::string getTypeName(const DataType t)
{
	switch (t)
	{
		case DataType::INT:
		{
			return "INT";
		}
		case DataType::DOUBLE:
		{
			return "DOUBLE";
		}
		case DataType::UNDEFINED:
		{
			return "UNDEFINED";
		}
		case DataType::BOOL:
		{
			return "BOOL";
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
