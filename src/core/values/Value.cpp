#include "Value.hpp"

#include <string.h>
#include <stdlib.h>
#include <bitset>

#include <core/values/types/Typer.hpp>
#include <core/misc/Debug.hpp>

Value::Value()
{
	type_ = UNDEFINED;
	value_.i = 0;
}

template<typename T>
Value::Value(T t)
{
	set(t);
}

template Value::Value(double t);
template Value::Value(long int t);
template Value::Value(bool t);

Value::Value(ValueType type)
{
	type_ = type;
	value_.i = 0;
}

template<typename T>
T Value::get() const
{
	if (!Typer<T>::matches(type_))
	{
		return 0;
	}
	switch (type_)
	{
		case BOOL:
		{
			return value_.b;
		}
		case DOUBLE:
		{
			return value_.d;
		}
		case INT:
		{
			return value_.i;
		}
		default:
		{
			return 0;
		}
	}
	return 0;
}

template double Value::get() const;
template long int Value::get() const;
template bool Value::get() const;

template <typename T>
void Value::set(T t)
{
	type_ = Typer<T>::toValueType();
	switch (type_)
	{
		case BOOL:
		{
			value_.b = t;
			break;
		}
		case DOUBLE:
		{
			value_.d = t;
			break;
		}
		case INT:
		{
			value_.i = t;
			break;
		}
		default:
		{
			type_ = ValueType::UNDEFINED;
			value_.i = 0;
			break;
		}
	}
}

template void Value::set(double t);
template void Value::set(long int t);
template void Value::set(bool t);

std::string Value::getString() const
{
	switch (type_)
	{
		case BOOL:
		{
			return value_.b?"true":"false";
		}
		case DOUBLE:
		{
			return std::to_string(value_.d);
		}
		case INT:
		{
			return std::to_string(value_.i);
		}
		default:
		{
			return "?";
		}
	}
	Debug::out << Debug::error << "Value::getString():" << Debug::endl;
	return "?";
}
