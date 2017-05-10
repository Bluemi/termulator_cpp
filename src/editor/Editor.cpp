#include "Editor.hpp"

#include <iostream>

#include <editor/controller/Controller.hpp>
#include <editor/controller/DefaultController.hpp>

//#include <core/misc/Debug.hpp>

Editor::Editor()
	: controller_(nullptr), running_(true), state_(CONSOLE), console_(1)
{
	window_ = initscr();
	controller_ = new DefaultController();
	raw();
	noecho();
	keypad(stdscr, true);
	clear();
	getmaxyx(window_, nrows_, ncols_);
	render();
}

Editor::~Editor()
{
	endwin();
	if (controller_ != nullptr)
		delete controller_;
	std::cout << "keystrokes:" << std::endl;
	for (char c : keystrokes)
	{
		std::cout << "\t" << (int)c << " : " << c << std::endl;
	}
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

void Editor::render()
{
	//Debug::debug << "hal";
	clear();
	refresh();
	console_.render();
}

void Editor::applyChar(const int c)
{
	keystrokes.push_back(c);
	if (c == TERMINATE_CHAR)
	{
		exit();
		return;
	}
	switch (state_)
	{
		case CONSOLE:
		{
			console_.applyChar(c);
			return;
		}
		case SYSTEMS:
		{
			controller_->applyKeyPress(c);
		}
	}
}
