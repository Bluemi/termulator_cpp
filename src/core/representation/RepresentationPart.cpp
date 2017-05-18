#include "RepresentationPart.hpp"

#include <core/misc/Debug.hpp>

RepresentationPart::RepresentationPart(std::string s)
	: text_(s), type_(RepresentationType::STRING_REPRESENTATION)
{}

RepresentationPart::RepresentationPart(RepresentationType t)
	: text_(""), type_(t)
{}

RepresentationType RepresentationPart::getType() const
{
	return type_;
}

void RepresentationPart::addString(const std::string& s)
{
	if (type_ != STRING_REPRESENTATION)
	{
		Debug::out << Debug::warn << "Representation::addString(): this RepresentationPart not of type STRING_REPRESENTATION" << Debug::endl;
		return;
	}
	text_.append(s);
}

std::string RepresentationPart::getString() const
{
	switch (type_)
	{
		case STRING_REPRESENTATION:
			return text_;
		case MARKERBEGIN_REPRESENTATION:
			return "<";
		case MARKEREND_REPRESENTATION:
			return ">";
		default:
			Debug::out << Debug::error << "RepresentationPart::getString(): default block :o" << Debug::endl;
	}
	return "";
}
