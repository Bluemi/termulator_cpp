#include "Panel.hpp"

Panel::Panel(const int y, const int x, const int height, const int width, RenderMode mode)
	: mode_(mode)
{
	window_ = newwin(height, width, y, x);
}

Panel::~Panel()
{
	delwin(window_);
}

void Panel::refresh()
{
	wrefresh(window_);
}

WINDOW* Panel::getWindow() const
{
	return window_;
}

void Panel::render()
{
	wmove(window_, 0, 0);
	if (mode_ == RenderMode::BORDER)
		wborder(window_, '|', '|', '-', '-', '+', '+', '+', '+');
}

void Panel::setRenderMode(RenderMode mode)
{
	mode_ = mode;
}
