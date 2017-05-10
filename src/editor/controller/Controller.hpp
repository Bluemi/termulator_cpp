#ifndef __CONTROLLER_CLASS__
#define __CONTROLLER_CLASS__

class System;

class Controller
{
	public:
		Controller();
		virtual ~Controller();
		void setTarget(System* target);
		virtual void applyKeyPress(const char c) = 0;
	protected:
		System* getTarget() const;
	private:
		System* target_;

};

#endif
