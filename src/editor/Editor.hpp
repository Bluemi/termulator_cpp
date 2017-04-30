#ifndef __EDITOR_CLASS__
#define __EDITOR_CLASS__

#include <curses.h>

#include <core/system/System.hpp>

class Editor
{
	enum InputState { CONSOLE };
	public:
		Editor();
		~Editor();
		void run();
		void exit();
	private:
		void render() const;
		void renderConsole() const;
		void applyChar(const char c);

		System system_;
		bool running_;
		InputState state_;
		int nrows_, ncols_;
		int cursorx_, cursory_;
		WINDOW* window_;
		std::string consoleText;

		char tmp_;
};

#endif
