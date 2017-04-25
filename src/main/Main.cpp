#include "Main.hpp"

#include <iostream>

#include <test/Test.hpp>
#include <core/terms/values/Value.hpp>

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
	std::cout << system_.getValue().getString() << std::endl;
}

void Main::init()
{
	Term* term = new Value();
	if (!system_.addChild(term))
	{
		std::cout << "ERROR: Main::init(): system.addChild() failed" << std::endl;
	}
}
