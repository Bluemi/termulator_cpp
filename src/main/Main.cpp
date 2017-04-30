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
	run();
}

void Main::run()
{
	editor_.run();
}
