#ifndef __TYPER_CLASS__
#define __TYPER_CLASS__

#include "ValueType.hpp"
#include "TypeMatcher.hpp"

template<typename T>
class Typer
{
	public:
		static ValueType toValueType();
		static bool matches(const ValueType& t);
};

template<typename T>
ValueType Typer<T>::toValueType()
{
	if (Typer<T>::matches(ValueType::INT))
	{
		return ValueType::INT;
	}
	else if (Typer<T>::matches(ValueType::DOUBLE))
	{
		return ValueType::DOUBLE;
	}
	else if (Typer<T>::matches(ValueType::BOOL))
	{
		return ValueType::DOUBLE;
	}
	return ValueType::UNDEFINED;
}

template <typename T>
bool Typer<T>::matches(const ValueType& t)
{
	switch (t)
	{
		case DOUBLE:
		{
			return TypeMatcher<T, double>::equals;
		}
		case INT:
		{
			return TypeMatcher<T, int>::equals;
		}
		case BOOL:
		{
			return TypeMatcher<T, bool>::equals;
		}
		default:
		{
			return false;
		}
	}
	return false;
}

#endif
