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

		void setShowMarker(const bool showMarker);
		bool showMarker() const;
	private:
		System* system_;
		bool showMarker_;
};

#endif
