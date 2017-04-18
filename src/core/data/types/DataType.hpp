#ifndef __DATATYPE_CLASS__
#define __DATATYPE_CLASS__

#include <string>

enum DataType : char { UNDEFINED, BOOL, DOUBLE, INT };

std::string getTypeName(DataType);

// UNDEFINED does not match UNDEFINED
bool matches(const DataType&, const DataType&);

#endif
