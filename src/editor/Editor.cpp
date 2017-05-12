#include "Editor.hpp"

#include <iostream>

#include <editor/controller/Controller.hpp>
#include <editor/controller/DefaultController.hpp>

#include <core/misc/Debug.hpp>

Editor::Editor()
	: controller_(nullptr), running_(true), state_(CONSOLE), console_(LINES-1)
{
	controller_ = new DefaultController();
	render();
}

Editor::~Editor()
{
	endwin();
	if (controller_ != nullptr)
		delete controller_;
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

void Editor::applyQuitMessage(const QuitMessage& m)
{
	exit();
}

void Editor::render()
{
	clear();
	refresh();
	console_.render();
	refresh();
}

void Editor::applyChar(const int c)
{
	Debug::out << "Editor::keystroke: \"" << c << "\"" << Debug::endl;
	switch (state_)
	{
		case CONSOLE:
		{
			console_.applyChar(c);
			while (console_.hasMessage())
			{
				Message* m = console_.pollMessage();
				m->dispatch(this);
				delete m;
			}
			return;
		}
		case SYSTEMS:
		{
			controller_->applyKeyPress(c);
		}
	}
}
