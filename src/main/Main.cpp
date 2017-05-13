#include "Main.hpp"

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
	// initiate ncurses
	initscr();
	raw();
	noecho();
	keypad(stdscr, true);
	curs_set(0);
	clear();
	//ESCDELAY = 10;
	editor_ = new Editor();
	editor_->run();
}
