#include "Debug.hpp"

#include <iostream>

Debug::DebugClass Debug::out;

Debug::DebugClass::DebugClass()
{
	strings_.push_back("");
}

Debug::DebugClass::~DebugClass()
{
	for (auto iter = strings_.begin(); iter != strings_.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
}

Debug::DebugClass& Debug::DebugClass::operator<<(const int i)
{
	strings_.back().append(std::to_string(i));
	return *this;
}

Debug::DebugClass& Debug::DebugClass::operator<<(const float f)
{
	strings_.back().append(std::to_string(f));
	return *this;
}

Debug::DebugClass& Debug::DebugClass::operator<<(const std::string s)
{
	strings_.back().append(s);
	return *this;
}

Debug::DebugClass& Debug::DebugClass::operator<<(const Debug::Tag tag)
{
	switch (tag)
	{
		case Debug::Tag::endl:
		{
			strings_.push_back("");
			break;
		}
		case Debug::Tag::error:
		{
			strings_.back().append(ERROR_COLOR).append("ERROR: ").append(DEFAULT_COLOR);
			break;
		}
		case Debug::Tag::warn:
		{
			strings_.back().append(WARN_COLOR).append("WARN : ").append(DEFAULT_COLOR);
			break;
		}
		case Debug::Tag::note:
		{
			strings_.back().append(NOTE_COLOR).append("NOTE : ").append(DEFAULT_COLOR);
			break;
		}
		case Debug::Tag::test:
		{
			strings_.back().append(TEST_COLOR).append("TEST : ").append(DEFAULT_COLOR);
			break;
		}
	}
	return *this;
}
