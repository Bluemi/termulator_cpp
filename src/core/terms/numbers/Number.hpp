#ifndef __NUMBER_CLASS__
#define __NUMBER_CLASS__

/*
	represents a human writable number like 0.5 or 0.123, if behavior is equal to "FLOAT_BEHAVIOR" or represents ints, if behavior is set to "INT_BEHAVIOR".
	Cannot represent rational numbers like 1/3 exactly.
	The represented value is equal to Coefficient * 10 ^ Exponent.
*/

#include <string>

#include <core/terms/Term.hpp>

constexpr int DEFAULT_PRECISION = 5;

class Number : public Term
{
	public:
		Number(int precision = DEFAULT_PRECISION);
		~Number();

		virtual ValueType getValueType() const override;
		virtual bool hasValue() const override;

		// Approx
		virtual Value getValue() const override;
	 	void setValue(const double value);
		void setPrecision(const int precision);
		int getPrecision() const;
		long int getCoefficient() const;
		long int getExponent() const;

		std::string getString(Stringable* markedStringable = nullptr) const override;

		// parse
		bool parse(const std::string& s);

		// operations
		Number operator+(const Number& value) const;
		Number operator-(const Number& value) const;
		Number operator*(const Number& value) const;
		Number operator/(const Number& value) const;
		bool operator==(const Number& value) const;
	private:
		long int coefficient_;
		long int exponent_;
		int precision_;
};

#endif
