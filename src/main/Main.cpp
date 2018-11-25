#include "Main.hpp"

#include <ncurses.h>

#include <core/terms/numbers/Number.hpp>
#include <core/terms/operations/Addition.hpp>
#include <core/misc/Debug.hpp>
#include <core/system/System.hpp>
#include <editor/Editor.hpp>
#include <test/Test.hpp>

void run();
void init_curses();

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
