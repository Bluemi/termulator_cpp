#include "TextBox.hpp"

#include <core/misc/Debug.hpp>

TextBox::TextBox(int y, int x, int height, int width, RenderMode mode)
	: Panel(y, x, height, width, mode)
{}

TextBox::~TextBox()
{
}

void TextBox::subRender()
{
	Debug::out << Debug::error << "TextBox::render(): should never be called" << Debug::endl;
}

void TextBox::renderText(const std::string& text)
{
	wmove(getWindow(), 1,1);
	waddstr(getWindow(), text.c_str());
}
