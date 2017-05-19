#ifndef __SYSTEMTEXTBOX_CLASS__
#define __SYSTEMTEXTBOX_CLASS__

#include <editor/ui/TextBox.hpp>

class System;

class SystemTextBox : public TextBox
{
	public:
		SystemTextBox(int y, int x, const bool showMarker = true);
		virtual ~SystemTextBox();
		virtual void subRender() override;

		void setSystem(System* s);
		System* getSystem() const;

		void setShowMarker(const bool showMarker);
		bool showMarker() const;

		void insertChar(const char c);
		void finishInsertion();

		bool hasSystem() const;
	private:
		enum InputState : unsigned char
		{
			NORMAL_STATE,
			INPUT_STATE
		};
		System* system_;
		bool showMarker_;
		InputState state_;
		std::string inputString_;
};

#endif
