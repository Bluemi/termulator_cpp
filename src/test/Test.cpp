#include "Test.hpp"

#include <iostream>

#include <core/terms/values/Value.hpp>

void testValueSetValue()
{
	Value v;
	/*
	for (double i = -100; i < 200; i += 2)
	{
		v.setValue(i);
		if (v.getValue().get<double>() != i)
		{
			std::cout << "testValueSetValue(): Failure when i = " << i << std::endl;
		}
	}
	*/
	v.setValue(10.2);
	std::cout << "testValueSetValue(): 10.2 = " << v.getString() << std::endl;
}

void testValuePlus()
{
	double a = -100.0;
	Value aValue;
	Value bValue;
	for (double b = -10.0; b < 20.0; b++)
	{
		aValue.setValue(a);
		bValue.setValue(b);
		std::cout << a << " + " << b << " = " << (aValue + bValue).getValue().get<double>() << std::endl;
		a += 9;
	}
}

void testValueMinus()
{
	double a = -100.0;
	Value aValue;
	Value bValue;
	for (double b = -10.0; b < 20.0; b++)
	{
		aValue.setValue(a);
		bValue.setValue(b);
		std::cout << a << " - " << b << " = " << (aValue - bValue).getValue().get<double>() << std::endl;
		a += 9;
	}
}

void testValueMulti()
{
	double a = -100.0;
	Value aValue;
	Value bValue;
	for (double b = -10.0; b < 20.0; b++)
	{
		aValue.setValue(a);
		bValue.setValue(b);
		std::cout << a << " * " << b << " = " << (aValue * bValue).getValue().get<double>() << std::endl;
		a += 9;
	}
}

void testValueDivision()
{
	double a = -100.0;
	Value aValue;
	Value bValue;
	for (double b = -10.0; b < 20.0; b++)
	{
		aValue.setValue(a);
		bValue.setValue(b);
		std::cout << a << " / " << b << " = " << (aValue / bValue).getValue().get<double>() << std::endl;
		a += 9;
	}
}

#include <vector>

void testValueParse()
{
	Value v;
	std::vector<std::string> str{"1234", "0000.000004567", "0,0023", "543.1234"};
	for (unsigned int i = 0; i < str.size(); i++)
	{
		v.parse(str[i]);
		std::cout << str[i] << " = " << v.getString() << "\t exponent = " << v.getExponent() << "\t coefficient = " << v.getCoefficient() << std::endl;
	}
}

Test::Test()
{
	//testValueSetValue();
	//testValuePlus();
	//testValueMinus();
	//testValueMulti();
	//testValueDivision();
	testValueParse();
}
