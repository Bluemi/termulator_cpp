#ifndef __CONTROLLER_CLASS__
#define __CONTROLLER_CLASS__

class SystemTextBox;

class Controller
{
	public:
		Controller();
		virtual ~Controller();
		void setTarget(SystemTextBox* target);
		virtual void applyKeyPress(const char c) = 0;
		bool hasTarget() const;
	protected:
		SystemTextBox* getTarget() const;
	private:
		SystemTextBox* target_;

};

#endif
