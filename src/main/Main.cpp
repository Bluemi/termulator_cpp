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
	uninit();
}

void Main::run()
{
	std::cout << system_.getValue().getString() << std::endl;
}

void Main::init()
{
	Term* term = new Value();
	system_.addChild(term);
}

void Main::uninit()
{
	std::cout << "Main::uninit() TODO" << std::endl;
}
