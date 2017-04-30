#ifndef __MAIN_CLASS__
#define __MAIN_CLASS__

#include <core/system/System.hpp>
#include <editor/Editor.hpp>

constexpr bool TEST = false;

class Main
{
	public:
		Main();
	private:
		void run();
		System system_;
		Editor editor_;
};

#endif
