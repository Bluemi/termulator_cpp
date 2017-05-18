#ifndef __REPRESENTABLE_CLASS__
#define __REPRESENTABLE_CLASS__

#include <core/representation/Representation.hpp>

class Representable
{
	public:
		Representable();
		virtual ~Representable();
		virtual Representation getRepresentation(Representable* markerRepresentable) const = 0;
};

#endif
