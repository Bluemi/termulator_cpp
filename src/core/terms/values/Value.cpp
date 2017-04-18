#include "Value.hpp"


#include <iostream>
#include <tgmath.h>

Value::Value(const int precision)
	: coefficient_(0), exponent_(0), precision_(precision)
{}

Value::~Value()
{}

DataType Value::getValueType() const
{
	return DataType::DOUBLE;
}

bool Value::hasValue() const
{
	return true;
}

// Value
Data Value::getValue() const
{
	return Data(coefficient_ * pow(10.0, exponent_));
}

void Value::setValue(const double value)
{
	if (value == 0.0)
	{
		coefficient_ = 0;
		exponent_ = 0;
		return;
	}
	// coefficient = 2.2 * 10^5 = 220000
	long int coefficient = (int)(value * pow(10.0, precision_));
	// exponent = -5
	long int exponent = -precision_;
	int i = 0;
	while (coefficient % 10 == 0)
	{
		coefficient /= 10;
		i++;
	}
	exponent_ = exponent + i;
	coefficient_ = coefficient;
}

void Value::setPrecision(const int precision)
{
	if (precision >= 0)
	{
		precision_ = precision;
	}
}

int Value::getPrecision() const
{
	return precision_;
}

std::string Value::getString() const
{
	return "";
}

// parse
bool parseInt(const std::string& s)
{
	std::cout << "Value::parseInt(): TODO" << std::endl;
	return false;
}

bool Value::parseFloat(const std::string& s)
{
	std::cout << "Value::parseInt(): TODO" << std::endl;
	return false;
}

// operations
Value Value::operator+(const Value& value) const
{
	Value result;
	if (this->exponent_ > value.coefficient_)
	{
		const long int aValue = this->coefficient_ * pow(10.0, this->exponent_ - value.exponent_);
		result.exponent_ = value.exponent_;
		result.coefficient_ = aValue + value.coefficient_;
	}
	else if (this->exponent_ < value.exponent_)
	{
		const long int aValue = value.coefficient_ * pow(10.0, value.exponent_ - this->exponent_);
		result.exponent_ = this->exponent_;
		result.coefficient_ = aValue + this->coefficient_;
	}
	else
	{
		result.exponent_ = this->exponent_;
		result.coefficient_ = this->coefficient_ + value.coefficient_;
	}

	return result;
}

Value Value::operator-(const Value& value) const
{
	Value result;
	if (this->exponent_ > value.coefficient_)
	{
		const long int aValue = this->coefficient_ * pow(10.0, this->exponent_ - value.exponent_);
		result.exponent_ = value.exponent_;
		result.coefficient_ = aValue - value.coefficient_;
	}
	else if (this->exponent_ < value.exponent_)
	{
		const long int aValue = value.coefficient_ * pow(10.0, value.exponent_ - this->exponent_);
		result.exponent_ = this->exponent_;
		result.coefficient_ = aValue - this->coefficient_;
	}
	else
	{
		result.exponent_ = this->exponent_;
		result.coefficient_ = this->coefficient_ - value.coefficient_;
	}

	return result;
}

Value Value::operator*(const Value& value) const
{
	Value result;
	result.exponent_ = this->exponent_ + value.exponent_;
	result.coefficient_ = this->coefficient_ * value.coefficient_;
	return result;
}

Value Value::operator/(const Value& value) const
{
	if (value.coefficient_ == 0)
	{
		return Value();
	}
	Value result;
	result.setValue(this->getValue().get<double>() / value.getValue().get<double>());
	return result;
}

bool Value::operator==(const Value& value) const
{
	std::cout << "Value::operator==(): TODO" << std::endl;
	return false;
}
