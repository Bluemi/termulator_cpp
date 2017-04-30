#include "Main.hpp"

#include <iostream>

#include <test/Test.hpp>
#include <core/terms/numbers/Number.hpp>
#include <core/terms/operations/Addition.hpp>

int main()
{
	if (!TEST)
	{
		Main m;
	}
	else
	{
		Test t;
	}
	return 0;
}

Main::Main()
{
	init();
	run();
}

void Main::run()
{
	std::cout << "Term: " << system_.getString() << std::endl;
	std::cout << "adding Number" << std::endl;
	Number* value = new Number();
	value->parse("10.2");
	if (!system_.addChild(value))
	{
		std::cout << "ERROR: Main::init(): system.addChild() failed" << std::endl;
	}
	std::cout << "Term: " << system_.getString() << std::endl;
	std::cout << "adding Addition" << std::endl;
	Term* term = new Addition();
	if (!system_.addChild(term))
	{
		std::cout << "ERROR: Main::init(): system.addChild() failed" << std::endl;
	}
	std::cout << "Term: " << system_.getString() << std::endl;
}

void Main::init()
{
}
