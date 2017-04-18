#include "System.hpp"

#include <iostream>

System::System()
	: root(nullptr)
{}

void System::addTerm(Term* term)
{
	if (root == nullptr)
	{
		root = term;
		branch.push(term);
	}
	else
	{
		std::cout << "System::addTerm(): TODO" << std::endl;
		root->isContainer();
	}
}

Data System::getValue() const
{
	if (root == nullptr)
	{
		return Data();
	}
	if (!root->hasValue())
	{
		return Data();
	}
	return root->getValue();
}

std::string System::getSystemString() const
{
	if (root == nullptr)
	{
		return "";
	}
	return root->getString();
}
