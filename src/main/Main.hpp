#ifndef __MAIN_CLASS__
#define __MAIN_CLASS__

#include <core/system/System.hpp>

constexpr bool TEST = false;

class Main
{
	public:
		Main();
	private:
		void init();
		void run();
		System system_;
};

#endif
