#ifndef __REPRESENTATIONPART_CLASS__
#define __REPRESENTATIONPART_CLASS__

#include <string>

#include "RepresentationType.hpp"

class RepresentationPart
{
	public:
		RepresentationPart(std::string s);
		RepresentationPart(RepresentationType t);
		RepresentationType getType() const;
		void addString(const std::string& s);
		std::string getString() const;
	private:
		std::string text_;
		RepresentationType type_;
};

#endif
