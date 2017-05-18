#include "SystemTextBox.hpp"

#include <core/misc/Debug.hpp>
#include <core/system/System.hpp>

SystemTextBox::SystemTextBox(int y, int x, const bool showMarker)
	: TextBox(y, x, 4, 20, RenderMode::CLEAR), system_(nullptr), showMarker_(showMarker)
{}

SystemTextBox::~SystemTextBox()
{
	delete system_;
}

void SystemTextBox::subRender()
{
	if (system_ == nullptr)
	{
		Debug::out << Debug::error << "SystemTextBox::subRender(): system_ == nullptr" << Debug::endl;
		return;
	}
	TextBox::renderText(system_->getRepresentation(nullptr).getString());
}

void SystemTextBox::setSystem(System* s)
{
	system_ = s;
}

void SystemTextBox::setShowMarker(const bool showMarker)
{
	showMarker_ = showMarker;
}

bool SystemTextBox::showMarker() const
{
	return showMarker_;
}
