#ifndef __VALUETYPE_CLASS__
#define __VALUETYPE_CLASS__

#include <string>

enum ValueType : char { UNDEFINED, BOOL, DOUBLE, INT };

std::string getTypeName(ValueType);

// UNDEFINED does not match UNDEFINED
bool matches(const ValueType&, const ValueType&);

#endif
