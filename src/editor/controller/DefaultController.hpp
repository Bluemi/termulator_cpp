#ifndef __DEFAULTCONTROLLER_CLASS__
#define __DEFAULTCONTROLLER_CLASS__

#include "Controller.hpp"

class DefaultController : public Controller
{
	public:
		DefaultController();
		virtual ~DefaultController();
		virtual void applyKeyPress(const char c) override;
};

#endif
