#include "Data.hpp"

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
