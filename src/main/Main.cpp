#include "Main.hpp"

#include <iostream>

#include <test/Test.hpp>
#include <core/terms/values/Value.hpp>
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
	std::cout << system_.getString() << std::endl;
}

void Main::init()
{
	std::cout << "adding addition" << std::endl;
	Term* term = new Addition();
	if (!system_.addChild(term))
	{
		std::cout << "ERROR: Main::init(): system.addChild() failed" << std::endl;
	}
	std::cout << "adding second addition" << std::endl;
	term = new Addition();
	if (!system_.addChild(term))
	{
		std::cout << "ERROR: Main::init(): system.addChild() failed" << std::endl;
	}
}
