#include "Data.hpp"

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <bitset>

#include <core/data/types/Typer.hpp>

Data::Data()
{
	type_ = UNDEFINED;
	data_.i = 0;
}

template<typename T>
Data::Data(T t)
{
	set(t);
}

template Data::Data(double t);
template Data::Data(long int t);
template Data::Data(bool t);

Data::Data(DataType type)
{
	type_ = type;
	data_.i = 0;
}

template<typename T>
T Data::get() const
{
	if (!Typer<T>::matches(type_))
	{
		return 0;
	}
	switch (type_)
	{
		case BOOL:
		{
			return data_.b;
		}
		case DOUBLE:
		{
			return data_.d;
		}
		case INT:
		{
			return data_.i;
		}
		default:
		{
			return 0;
		}
	}
	return 0;
}

template double Data::get() const;
template long int Data::get() const;
template bool Data::get() const;

template <typename T>
void Data::set(T t)
{
	type_ = Typer<T>::toDataType();
	switch (type_)
	{
		case BOOL:
		{
			data_.b = t;
			break;
		}
		case DOUBLE:
		{
			data_.d = t;
			break;
		}
		case INT:
		{
			data_.i = t;
			break;
		}
		default:
		{
			type_ = DataType::UNDEFINED;
			data_.i = 0;
			break;
		}
	}
}

template void Data::set(double t);
template void Data::set(long int t);
template void Data::set(bool t);

std::string Data::getString() const
{
	switch (type_)
	{
		case BOOL:
		{
			return data_.b?"true":"false";
		}
		case DOUBLE:
		{
			return std::to_string(data_.d);
		}
		case INT:
		{
			return std::to_string(data_.i);
		}
		default:
		{
			return "?";
		}
	}
	std::cout << "Data::getString(): ERROR" << std::endl;
	return "?";
}
