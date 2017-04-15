#ifndef __VALUE_CLASS__
#define __VALUE_CLASS__

/*
	represents a human writable number like 0.5 or 0.123, if behavior is equal to "FLOAT_BEHAVIOR" or represents ints, if behavior is set to "INT_BEHAVIOR".
	Cannot represent rational numbers like 1/3 exactly.
	The represented value is equal to Coefficient * 10 ^ Exponent.
*/

#include <string>

class Value
{
	public:
		// defines how the Value acts
		enum Behavior { FLOAT_BEHAVIOR, INT_BEHAVIOR };

		Value(const Behavior behavior);
		~Value();

		// Approx
		double getApprox() const;
	 	void setApprox(const double value);

		std::string getString() const;

		// parse
		bool parseInt(const std::string& s);
		bool parseFloat(const std::string& s);

		// Behavior
		Behavior getBehavior() const;
		void setBehavior(const Behavior behavior);

		// operations
		Value operator+(const Value& value) const;
		Value operator-(const Value& value) const;
		Value operator*(const Value& value) const;
		Value operator/(const Value& value) const;
		bool operator==(const Value& value) const;
	private:
		Behavior behavior_;
		long int coefficient_;
		long int exponent_;
};

#endif
