#ifndef __TEXTBOX_CLASS__
#define __TEXTBOX_CLASS__

#include "Panel.hpp"
#include <core/interfaces/Stringable.hpp>

class TextBox : public Panel
{
	public:
		TextBox(Stringable* source, int y, int x, int height, int width, RenderMode mode = RenderMode::BORDER);
		virtual ~TextBox();
		virtual void render() override;
	protected:
		bool hasSource() const;
		Stringable* getSource() const;
		void setSource(Stringable* source);
	private:
		Stringable* source_;
};

#endif
