#include "Number.hpp"

#include <tgmath.h>

#include <core/misc/Debug.hpp>

Number::Number(const int precision)
	: coefficient_(0), exponent_(0), precision_(precision)
{}

Number::~Number()
{}

ValueType Number::getValueType() const
{
	return ValueType::DOUBLE;
}

bool Number::hasValue() const
{
	return true;
}

//Number 
Value Number::getValue() const
{
	return Value(coefficient_ * pow(10.0, exponent_));
}

void Number::setValue(const double number)
{
	if (number == 0.0)
	{
		coefficient_ = 0;
		exponent_ = 0;
		return;
	}
	// coefficient = 2.2 * 10^5 = 220000
	long int coefficient = (int)(number * pow(10.0, precision_));
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

void Number::setPrecision(const int precision)
{
	if (precision >= 0)
	{
		precision_ = precision;
	}
}

int Number::getPrecision() const
{
	return precision_;
}

long int Number::getCoefficient() const
{
	return coefficient_;
}

long int Number::getExponent() const
{
	return exponent_;
}

Representation Number::getRepresentation(Representable* markedRepresentable) const
{
	if (coefficient_ == 0)
	{
		return Representation("0");
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
	if (markedRepresentable == this)
	{
		return "<" + s + ">";
	}
	return Representation(s);
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

bool Number::parse(const std::string& s)
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
Number Number::operator+(const Number& number) const
{
	Number result;
	if (this->exponent_ > number.coefficient_)
	{
		const long int aNumber = this->coefficient_ * pow(10.0, this->exponent_ - number.exponent_);
		result.exponent_ = number.exponent_;
		result.coefficient_ = aNumber + number.coefficient_;
	}
	else if (this->exponent_ < number.exponent_)
	{
		const long int aNumber = number.coefficient_ * pow(10.0, number.exponent_ - this->exponent_);
		result.exponent_ = this->exponent_;
		result.coefficient_ = aNumber + this->coefficient_;
	}
	else
	{
		result.exponent_ = this->exponent_;
		result.coefficient_ = this->coefficient_ + number.coefficient_;
	}

	return result;
}

Number Number::operator-(const Number& number) const
{
	Number result;
	if (this->exponent_ > number.coefficient_)
	{
		const long int aNumber = this->coefficient_ * pow(10.0, this->exponent_ - number.exponent_);
		result.exponent_ = number.exponent_;
		result.coefficient_ = aNumber - number.coefficient_;
	}
	else if (this->exponent_ < number.exponent_)
	{
		const long int aNumber = number.coefficient_ * pow(10.0, number.exponent_ - this->exponent_);
		result.exponent_ = this->exponent_;
		result.coefficient_ = aNumber - this->coefficient_;
	}
	else
	{
		result.exponent_ = this->exponent_;
		result.coefficient_ = this->coefficient_ - number.coefficient_;
	}

	return result;
}

Number Number::operator*(const Number& number) const
{
	Number result;
	result.exponent_ = this->exponent_ + number.exponent_;
	result.coefficient_ = this->coefficient_ * number.coefficient_;
	return result;
}

Number Number::operator/(const Number& number) const
{
	if (number.coefficient_ == 0)
	{
		return Number();
	}
	Number result;
	result.setValue(this->getValue().get<double>() / number.getValue().get<double>());
	return result;
}

bool Number::operator==(const Number& number) const
{
	Debug::out << "Number::operator==(): TODO" << Debug::endl;
	return false;
}
