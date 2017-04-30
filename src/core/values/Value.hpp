#ifndef __VALUE_CLASS__
#define __VALUE_CLASS__

#include <core/values/types/ValueType.hpp>

union Datum
{
	double d;
	long int i;
	bool b;
};

class Value
{
	public:
		Value();
		template<typename T>
		Value(T t);
		Value(ValueType type);
		template<typename T>
		T get() const;
		template <typename T>
		void set(T t);
		std::string getString() const;
	private:
		Datum value_;
		ValueType type_;
};

#endif
