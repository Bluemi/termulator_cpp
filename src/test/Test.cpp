#include "Test.hpp"

#include <iostream>

#include <core/terms/values/Value.hpp>

void testValueSetValue()
{
	Value v;
	for (double i = -100; i < 200; i += 2)
	{
		v.setValue(i);
		if (v.getValue().get<double>() != i)
		{
			std::cout << "Failure when i = " << i << std::endl;
		}
	}
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

Test::Test()
{
	//testValueSetValue();
	//testValuePlus();
	//testValueMinus();
	//testValueMulti();
	testValueDivision();
}
