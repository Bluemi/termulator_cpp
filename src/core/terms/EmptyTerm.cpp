#include "EmptyTerm.hpp"

EmptyTerm::EmptyTerm()
{}

EmptyTerm::~EmptyTerm()
{}

Data EmptyTerm::getValue() const
{
	return Data();
}

DataType EmptyTerm::getValueType() const
{
	return DataType::UNDEFINED;
}

bool EmptyTerm::hasValue() const
{
	return false;
}

std::string EmptyTerm::getString() const
{
	return "_";
}

bool EmptyTerm::isEmptyTerm() const
{
	return true;
}
