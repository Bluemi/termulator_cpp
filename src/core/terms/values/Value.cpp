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

long int Value::getCoefficient() const
{
	return coefficient_;
}

long int Value::getExponent() const
{
	return exponent_;
}

std::string Value::getString() const
{
	if (coefficient_ == 0)
	{
		return "0";
	}
	std::string s = std::to_string(coefficient_);
	if (exponent_ > 0)
	{
		for (int i = 0; i < exponent_; i++)
		{
			s += "0";
		}
	}
	else if (exponent_ < 0)
	{
		if ((int)s.length() <= (-exponent_))
		{
			const int slength = s.length();
			for (unsigned int i = 0; i <= (-exponent_ - slength); i++)
			{
				s.insert(0, "0");
			}
			s.insert(1, ".");
		}
		else
		{
			s.insert(s.length() + exponent_, ".");
		}
	}
	return s;
}

int toDigit(const char c)
{
	switch (c)
	{
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
	}
	return -1;
}

bool isDelimiter(char c)
{
	return ((c == '.') || (c == ','));
}

bool Value::parse(const std::string& s)
{
	int c(0);
	int e(0);
	bool delimiterFound = false;
	for (unsigned int i = 0; i < s.length(); i++)
	{
		if (delimiterFound)
		{
			e++;
		}
		const int digit = toDigit(s[i]);
		if (digit == -1)
		{
			if (isDelimiter(s[i]))
			{
				if (delimiterFound)
				{
					return false;
				}
				else
				{
					delimiterFound = true;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			c *= 10;
			c += digit;
		}
	}
	exponent_ = -e;
	coefficient_ = c;
	return true;
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
