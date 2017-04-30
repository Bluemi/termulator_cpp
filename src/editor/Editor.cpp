#include "Editor.hpp"

#include <iostream>

Editor::Editor()
	: running_(true), state_(CONSOLE), cursorx_(0), cursory_(0)
{
	window_ = initscr();
	//cbreak();
	noecho();
	clear();
	getmaxyx(window_, nrows_, ncols_);
}

Editor::~Editor()
{
	endwin();
	std::cout << "c = " << (int)tmp_ << " | " << tmp_ << std::endl;
}

void Editor::run()
{
	while (running_)
	{
		applyChar(getch());
		render();
	}
}

void Editor::exit()
{
	running_ = false;
}

void Editor::render() const
{
	clear();
	renderConsole();
	move(cursory_, cursorx_);
	refresh();
}

void Editor::renderConsole() const
{
	move(nrows_-1, 0);
	for (auto iter = consoleText.begin(); iter != consoleText.end(); ++iter)
	{
		addch(*iter);
	}
}

bool drawableSign(const char c)
{
	if ((c >= 32) && (c <= 126))
	{
		return true;
	}
	return false;
}

void Editor::applyChar(const char c)
{
	if (c != 27)
		tmp_ = c;
	switch (state_)
	{
		case CONSOLE:
		{
			if (c == 27)
			{
				running_ = false;
				return;
			}
			if (drawableSign(c))
			{
				consoleText.push_back(c);
				return;
			}
			if (c == 127)
			{
				if (consoleText.size() > 0)
					consoleText.pop_back();
			}
		}
	}
}
