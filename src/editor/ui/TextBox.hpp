#ifndef __TEXTBOX_CLASS__
#define __TEXTBOX_CLASS__

#include <string>

#include "Panel.hpp"

class TextBox : public Panel
{
	public:
		TextBox(int y, int x, int height, int width, RenderMode mode = RenderMode::BORDER);
		virtual ~TextBox();
		virtual void subRender() override;
	protected:
		void renderText(const std::string& text);
};

#endif
