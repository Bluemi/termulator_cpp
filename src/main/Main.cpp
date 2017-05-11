#include "Main.hpp"

#include <iostream>
#include <ncurses.h>

#include <test/Test.hpp>
#include <core/terms/numbers/Number.hpp>
#include <core/terms/operations/Addition.hpp>
#include <core/misc/Debug.hpp>

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
	: editor_(nullptr)
{
	run();
}

Main::~Main()
{
	if (editor_ != nullptr)
		delete editor_;
}

void Main::run()
{
	initscr();
	Debug::out << "initscr" << Debug::endl;
	raw();
	noecho();
	keypad(stdscr, true);
	clear();
	editor_ = new Editor();
	editor_->run();
}
