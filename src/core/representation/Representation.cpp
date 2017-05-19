#include "Representation.hpp"

#include <core/misc/Debug.hpp>

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

void Representation::add(const RepresentationPart& part)
{
	parts_.push_back(part);
}

bool Representation::validIndex(const int i) const
{
	return (i >= 0) && (i < (int)parts_.size());
}

RepresentationPart Representation::getPart(const int i) const
{
	if (!validIndex(i))
	{
		Debug::out << Debug::warn << "Representation::getPart(): invalid index=" << i << " size=" << (int)parts_.size() << Debug::endl;
		return RepresentationPart(RepresentationType::STRING_REPRESENTATION);
	}
	return parts_[i];
}

int Representation::getSize() const
{
	return parts_.size();
}
