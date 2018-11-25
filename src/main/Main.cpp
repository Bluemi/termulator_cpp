#include "Main.hpp"

#include <ncurses.h>

#include <test/Test.hpp>
#include <core/terms/numbers/Number.hpp>
#include <core/terms/operations/Addition.hpp>
#include <core/misc/Debug.hpp>

void run();
void init_curses();

int main()
{
	if (!TEST)
	{
		init_curses();
		run();
	}
	else
	{
		Test t;
	}
	return 0;
}

void init_curses()
{
	initscr();
	raw();
	noecho();
	keypad(stdscr, true);
	curs_set(0);
	clear();
}

void run()
{
	Editor editor;
	editor.run();
}
