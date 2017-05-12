#ifndef __EDITOR_CLASS__
#define __EDITOR_CLASS__

#include <curses.h>

#include <core/system/System.hpp>
#include <editor/console/Console.hpp>

#include <editor/messages/MessageListener.hpp>

class Controller;

class Editor : public MessageListener
{
	enum InputState { CONSOLE, SYSTEMS };
	public:
		static const char TERMINATE_CHAR = 27;
		Editor();
		~Editor();
		void run();
		void exit();

		// messageListener-Functions
		virtual void applyQuitMessage(const QuitMessage& m) override;
	private:
		void render();
		void applyChar(const int c);
		void applyConsoleCommand();

		Controller* controller_;
		System system_;
		bool running_;
		InputState state_;
		Console console_;
};

#endif
