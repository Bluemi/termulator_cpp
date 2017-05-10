#include "Debug.hpp"

/*

#include <iostream>

Debug::Debug()
{
	strings_.push_back("");
}

Debug::~Debug()
{
	for (auto iter = strings_.begin(); iter != strings_.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
}

Debug& Debug::operator<<(const int i)
{
	strings_.back().append(std::to_string(i));
	return *this;
}

Debug& Debug::operator<<(const float f)
{
	strings_.back().append(std::to_string(f));
	return *this;
}

Debug& Debug::operator<<(const std::string s)
{
	strings_.back().append(s);
	return *this;
}

Debug& Debug::operator<<(const Debug::Tag tag)
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
		case Debug::Tag::note:
		{
			strings_.back().append(NOTE_COLOR).append("NOTE : ").append(DEFAULT_COLOR);
			break;
		}
	}
	return *this;
}
*/
