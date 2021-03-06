#ifndef __REPRESENTATION_CLASS__
#define __REPRESENTATION_CLASS__

#include <string>
#include <vector>

#include "RepresentationPart.hpp"

class Representation
{
	public:
		Representation();
		Representation(const std::string& s);

		std::string getString() const;
		void add(const std::string& s);
		void add(const Representation& rep);
		void addMarkerBegin();
		void addMarkerEnd();

		bool validIndex(const int i) const;
		RepresentationPart getPart(const int i) const;
		int getSize() const;
	private:
		void add(const RepresentationPart& part);
		std::vector<RepresentationPart> parts_;
};

#endif
