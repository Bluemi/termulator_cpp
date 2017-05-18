#include "Representation.hpp"

Representation::Representation()
{}

Representation::Representation(const std::string& s)
{
	parts_.push_back(RepresentationPart(s));
}

std::string Representation::getString() const
{
	std::string s("");
	for (RepresentationPart part : parts_)
	{
		s.append(part.getString());
	}
	return s;
}

void Representation::add(const std::string& s)
{
	if (!parts_.empty())
	{
		RepresentationPart* lastPart = &(parts_.back());
		if (lastPart->getType() == RepresentationType::STRING_REPRESENTATION)
		{
			lastPart->addString(s);
			return;
		}
	}
	parts_.push_back(RepresentationPart(s));
}

void Representation::add(const RepresentationPart& part)
{
	parts_.push_back(part);
}

void Representation::add(const Representation& rep)
{
	for (RepresentationPart p : rep.parts_)
	{
		this->parts_.push_back(p);
	}
}

void Representation::addMarkerBegin()
{
	add(RepresentationPart(RepresentationType::MARKERBEGIN_REPRESENTATION));
}

void Representation::addMarkerEnd()
{
	add(RepresentationPart(RepresentationType::MARKEREND_REPRESENTATION));
}
