#include "Test.hpp"

#include <iostream>

#include <core/terms/numbers/Number.hpp>

void testNumberSetValue()
{
	Number v;
	/*
	for (double i = -100; i < 200; i += 2)
	{
		v.setValue(i);
		if (v.getValue().get<double>() != i)
		{
			std::cout << "testNumberSetValue(): Failure when i = " << i << std::endl;
		}
	}
	*/
	v.setValue(10.2);
	std::cout << "testNumberSetValue(): 10.2 = " << v.getRepresentation(nullptr).getString() << std::endl;
}

void testNumberPlus()
{
	double a = -100.0;
	Number aNumber;
	Number bNumber;
	for (double b = -10.0; b < 20.0; b++)
	{
		aNumber.setValue(a);
		bNumber.setValue(b);
		std::cout << a << " + " << b << " = " << (aNumber + bNumber).getValue().get<double>() << std::endl;
		a += 9;
	}
}

void testNumberMinus()
{
	double a = -100.0;
	Number aNumber;
	Number bNumber;
	for (double b = -10.0; b < 20.0; b++)
	{
		aNumber.setValue(a);
		bNumber.setValue(b);
		std::cout << a << " - " << b << " = " << (aNumber - bNumber).getValue().get<double>() << std::endl;
		a += 9;
	}
}

void testNumberMulti()
{
	double a = -100.0;
	Number aNumber;
	Number bNumber;
	for (double b = -10.0; b < 20.0; b++)
	{
		aNumber.setValue(a);
		bNumber.setValue(b);
		std::cout << a << " * " << b << " = " << (aNumber * bNumber).getValue().get<double>() << std::endl;
		a += 9;
	}
}

void testNumberDivision()
{
	double a = -100.0;
	Number aNumber;
	Number bNumber;
	for (double b = -10.0; b < 20.0; b++)
	{
		aNumber.setValue(a);
		bNumber.setValue(b);
		std::cout << a << " / " << b << " = " << (aNumber / bNumber).getValue().get<double>() << std::endl;
		a += 9;
	}
}

#include <vector>

void testNumberParse()
{
	Number v;
	std::vector<std::string> str{"1234", "0000.000004567", "0,0023", "543.1234"};
	for (unsigned int i = 0; i < str.size(); i++)
	{
		v.parse(str[i]);
		std::cout << str[i] << " = " << v.getRepresentation(nullptr).getString() << "\t exponent = " << v.getExponent() << "\t coefficient = " << v.getCoefficient() << std::endl;
	}
}

Test::Test()
{
	//testNumberSetValue();
	//testNumberPlus();
	//testNumberMinus();
	//testNumberMulti();
	//testNumberDivision();
	testNumberParse();
}
