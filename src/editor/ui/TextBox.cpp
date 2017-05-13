#include "TextBox.hpp"

TextBox::TextBox(Stringable* source, int y, int x, int height, int width, RenderMode mode)
	: Panel(y, x, height, width, mode), source_(source)
{}

TextBox::~TextBox()
{
}

void TextBox::render()
{
	Panel::render();
	Panel::refresh();
}

bool TextBox::hasSource() const
{
	return (source_ != nullptr);
}

Stringable* TextBox::getSource() const
{
	return source_;
}

void TextBox::setSource(Stringable* source)
{
	source_ = source;
}
