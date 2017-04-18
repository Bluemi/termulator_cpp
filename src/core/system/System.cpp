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
	}
	else
	{
		std::cout << "System::addTerm(): TODO" << std::endl;
		root->isContainer();
	}
}

std::string System::getValue() const
{
	//return root->getValue();
	return "";
}

std::string System::getSystemString() const
{
	return "";
	//return root->getString();
}
