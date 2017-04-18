#ifndef __DATA_CLASS__
#define __DATA_CLASS__

#include <core/data/types/DataType.hpp>

union Datum
{
	double d;
	long int i;
	bool b;
};

class Data
{
	public:
		Data();
		template<typename T>
		Data(T t);
		Data(DataType type);
		template<typename T>
		T get() const;
		template <typename T>
		void set(T t);
		std::string getString() const;
	private:
		Datum data_;
		DataType type_;
};

#endif
