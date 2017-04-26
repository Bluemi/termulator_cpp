#ifndef __VALUE_CLASS__
#define __VALUE_CLASS__

/*
	represents a human writable number like 0.5 or 0.123, if behavior is equal to "FLOAT_BEHAVIOR" or represents ints, if behavior is set to "INT_BEHAVIOR".
	Cannot represent rational numbers like 1/3 exactly.
	The represented value is equal to Coefficient * 10 ^ Exponent.
*/

#include <string>

#include <core/terms/Term.hpp>

constexpr int DEFAULT_PRECISION = 5;

class Value : public Term
{
	public:
		Value(int precision = DEFAULT_PRECISION);
		~Value();

		virtual DataType getValueType() const override;
		virtual bool hasValue() const override;

		// Approx
		virtual Data getValue() const override;
	 	void setValue(const double value);
		void setPrecision(const int precision);
		int getPrecision() const;
		long int getCoefficient() const;
		long int getExponent() const;

		std::string getString() const;

		// parse
		bool parse(const std::string& s);

		// operations
		Value operator+(const Value& value) const;
		Value operator-(const Value& value) const;
		Value operator*(const Value& value) const;
		Value operator/(const Value& value) const;
		bool operator==(const Value& value) const;
	private:
		long int coefficient_;
		long int exponent_;
		int precision_;
};

#endif
