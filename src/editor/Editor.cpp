#include "Editor.hpp"

#include <editor/controller/Controller.hpp>
#include <editor/controller/DefaultController.hpp>

#include <core/misc/Debug.hpp>

Editor::Editor()
	: controller_(nullptr), running_(true), state_(CONSOLE), console_(LINES-1)
{
	controller_ = new DefaultController();
	controller_->setTarget(&system_);
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

void Editor::renderSystems()
{
	mvaddstr(2,2, system_.getSystemString().c_str());
}

void Editor::render()
{
	clear();
	refresh();
	renderSystems();
	console_.render();
	refresh();
}

void Editor::applyChar(const char c)
{
	//Debug::out << "c = " << c << Debug::endl;
	if (c == SYSTEM_CHAR)
	{
		if (state_ == CONSOLE)
		{
			state_ = SYSTEMS;
			return;
		}
	}
	if (c == CONSOLE_CHAR)
	{
		if (state_ == SYSTEMS)
		{
			state_ = CONSOLE;
			return;
		}
	}
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
