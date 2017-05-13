#ifndef __PANEL_CLASS__
#define __PANEL_CLASS__

#include <ncurses.h>

class Panel
{
	public:
		enum RenderMode { BORDER, CLEAR };

		Panel(const int y, const int x, const int height, const int width, RenderMode mode = RenderMode::BORDER);
		virtual ~Panel();
		void render();
		void setRenderMode(RenderMode mode);
	protected:
		virtual void subRender();
		void refresh();
		WINDOW* getWindow() const;
	private:
		WINDOW* window_;
		RenderMode mode_;
};

#endif
