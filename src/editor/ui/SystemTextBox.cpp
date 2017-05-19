#include "SystemTextBox.hpp"

#include <core/misc/Debug.hpp>
#include <core/system/System.hpp>
#include <core/terms/numbers/Number.hpp>

SystemTextBox::SystemTextBox(int y, int x, const bool showMarker)
	: TextBox(y, x, 4, 20, RenderMode::CLEAR), system_(nullptr), showMarker_(showMarker), state_(InputState::NORMAL_STATE)
{}

SystemTextBox::~SystemTextBox()
{
	delete system_;
}

void SystemTextBox::subRender()
{
	if (!hasSystem())
	{
		Debug::out << Debug::warn << "SystemTextBox::subRender(): system_ == nullptr" << Debug::endl;
		return;
	}
	if (state_ == InputState::INPUT_STATE)
	{
		Representation r = system_->getRepresentation();
		std::string s("");
		bool inMarker = false;
		for (int i = 0; i < r.getSize(); i++)
		{
			RepresentationPart p = r.getPart(i);
			if (!inMarker)
			{
				s += p.getString();
			}
			if (p.getType() == RepresentationType::MARKERBEGIN_REPRESENTATION)
			{
				s += inputString_;
				inMarker = true;
			}
			else if (p.getType() == RepresentationType::MARKEREND_REPRESENTATION)
			{
				inMarker = false;
				s += p.getString();
			}
		}
		TextBox::renderText(s);
	}
	else
	{
		TextBox::renderText(system_->getRepresentation().getString());
	}
}

void SystemTextBox::setSystem(System* s)
{
	system_ = s;
}

System* SystemTextBox::getSystem() const
{
	return system_;
}

void SystemTextBox::setShowMarker(const bool showMarker)
{
	showMarker_ = showMarker;
}

bool SystemTextBox::showMarker() const
{
	return showMarker_;
}

void SystemTextBox::insertChar(const char c)
{
	if (hasSystem())
	{
		if (!system_->canInsertChild())
		{
			return;
		}
	}
	else
	{
		Debug::out << Debug::warn << "SystemTextBox::insertChar(): no system" << Debug::endl;
		return;
	}
	state_ = InputState::INPUT_STATE;
	inputString_.push_back(c);
}

void SystemTextBox::finishInsertion()
{
	if (state_ != InputState::INPUT_STATE)
	{
		return;
	}
	state_ = InputState::NORMAL_STATE;
	if (hasSystem())
	{
		Number* n = new Number();
		if (!n->parse(inputString_))
		{
			Debug::out << Debug::warn << "SystemTextBox::finishInsertion(): inputString_ = \"" + inputString_ + "\"" << Debug::endl;
		}
		if (!system_->addChild(n))
		{
			Debug::out << Debug::warn << "SystemTextBox::finishInsertion(): addChild() return false" << Debug::endl;
		}
	}
	else
	{
		Debug::out << Debug::warn << "SystemTextBox::finishInsertion(): has no system_" << Debug::endl;
	}
	inputString_ = "";
}

bool SystemTextBox::hasSystem() const
{
	return (system_ != nullptr);
}
