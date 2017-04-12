#ifndef __VALUE_CLASS__
#define __VALUE_CLASS__


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

		// Behavior
		Behavior getBehavior() const;
		void setBehavior(const Behavior behavior);

		// operations
		void optimize();
		Value operator+(const Value& value) const;
		Value operator-(const Value& value) const;
		Value operator*(const Value& value) const;
		Value operator/(const Value& value) const;
		bool operator==(const Value& value) const;
	private:
		Behavior behavior_;
		long int numerator_;
		long int denominator_;
};

#endif
