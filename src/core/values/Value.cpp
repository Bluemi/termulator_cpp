#include "Value.hpp"

#include <iostream>

Value::Value(const Value::Behavior behavior)
	: behavior_(behavior)
{}

Value::~Value()
{}


// Approx
double Value::getApprox() const
{
	return (double)numerator_/(double)denominator_;
}

void Value::setApprox(const double value)
{
	std::cout << "Value::setApprox(): TODO" << std::endl;
}

// Behavior
Value::Behavior Value::getBehavior() const
{
	return behavior_;
}

void Value::setBehavior(const Value::Behavior behavior)
{
	behavior_ = behavior;
}

// operations

void Value::optimize()
{
	std::cout << "Value::optimize(): TODO" << std::endl;
}

Value::Behavior mergeBehaviors(const Value::Behavior& a, const Value::Behavior& b)
{
	if ((a == Value::Behavior::FLOAT_BEHAVIOR) || (b == Value::Behavior::FLOAT_BEHAVIOR))
	{
		return Value::Behavior::FLOAT_BEHAVIOR;
	}
	return Value::Behavior::INT_BEHAVIOR;
}

Value Value::operator+(const Value& value) const
{
	Value::Behavior newBehavior = mergeBehaviors(this->behavior_, value.behavior_);
	Value v(newBehavior);
	if (newBehavior == Value::Behavior::INT_BEHAVIOR)
	{
		v.numerator_ = this->numerator_ + value.numerator_;
		v.denominator_ = 1;
		return v;
	}
	
	v.denominator_ = this->denominator_ * value.denominator_;
	v.numerator_ = this->denominator_ * value.numerator_ + this->numerator_ * value.denominator_;
	return v;
}

Value Value::operator-(const Value& value) const
{
	Value::Behavior newBehavior = mergeBehaviors(this->behavior_, value.behavior_);
	Value v(newBehavior);
	if (newBehavior == Value::Behavior::INT_BEHAVIOR)
	{
		v.numerator_ = this->numerator_ - value.numerator_;
		v.denominator_ = 1;
		return v;
	}
	
	v.denominator_ = this->denominator_ * value.denominator_;
	v.numerator_ =  this->numerator_ * value.denominator_ - this->denominator_ * value.numerator_;
	return v;
}

Value Value::operator*(const Value& value) const
{
	Value::Behavior newBehavior(mergeBehaviors(this->behavior_, value.behavior_));
	Value v(newBehavior);
	if (newBehavior == Value::Behavior::INT_BEHAVIOR)
	{
		v.numerator_ = this->numerator_ * value.numerator_;
		v.denominator_ = 1;
		return v;
	}
	v.numerator_ = this->numerator_ * value.numerator_;
	v.denominator_ = this->denominator_ * value.denominator_;
	return v;
}

Value Value::operator/(const Value& value) const
{
	if (value.numerator_ == 0)
	{
		std::cout << "Value::operator/(): division by zero Error" << std::endl;
	}
	Behavior newBehavior(mergeBehaviors(this->behavior_, value.behavior_));
	Value v(newBehavior);
	if (newBehavior == Value::Behavior::INT_BEHAVIOR)
	{
		v.numerator_ = this->numerator_ / value.numerator_;
		v.denominator_ = 1;
		return v;
	}
	v.numerator_ = this->numerator_ * value.denominator_;
	v.denominator_ = this->denominator_ * value.numerator_;
	return v;
}

bool Value::operator==(const Value& value) const
{
	return (this->numerator_ == value.numerator_) && (this->denominator_ == value.denominator_);
}
