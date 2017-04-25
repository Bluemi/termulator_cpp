#include "System.hpp"

#include <iostream>

#include <core/terms/EmptyTerm.hpp>

System::System()
	: TermContainer(1)
{
	branch_.push_back(getRoot());
}

System::~System()
{
	while (!branch_.empty())
	{
		branch_.pop_back();
	}
}

Data System::getValue() const
{
	return getRoot()->getValue();
}

std::string System::getSystemString() const
{
	return getRoot()->getString();
}

DataType System::getValueType() const
{
	return getRoot()->getValueType();
}

bool System::isEmpty() const
{
	return getRoot()->isEmptyTerm();
}

Term* System::getTop() const
{
	return branch_[branch_.size()-1];
}

TermContainer* System::getLeafContainer()
{
	if (branch_.size() < 2)
	{
		return this;
	}
	return (TermContainer*)branch_[branch_.size()-2];
}

void System::addContainer(TermContainer* c)
{
	Term* oldTop = branch_[branch_.size()-1];
	TermContainer* oldTopContainer = getLeafContainer();
	if (!oldTopContainer->replace(oldTop, c))
	{
		std::cout << "ERROR: System::addContainer(): couldn't replace oldTop with c" << std::endl;
	}
	if (!c->addChild(oldTop))
	{
		delete oldTop;
	}
	branch_.pop_back();
	branch_.push_back(c);
}

bool System::addChild(Term* t)
{
	if (t == nullptr || t->isEmptyTerm())
	{
		return false;
	}
	if (t->isContainer())
	{
		addContainer((TermContainer*)t);
		return true;
	}
	if (getTop()->isContainer())
	{
		delete t;
		return false;
	}

	Term* oldTop = getTop();
	TermContainer* c = getLeafContainer();
	if (c->replace(oldTop, t))
	{
		delete oldTop;
		return true;
	}
	else
	{
		std::cout << "ERROR: System::addChild(): couldn't replace oldTop with t" << std::endl;
		delete t;
		return false;
	}
}

std::string System::getString() const
{
	return getRoot()->getString();
}

std::string System::getLinkSign() const
{
	return "";
}

bool System::replace(Term* victim, Term* replacement)
{
	if (getRoot() == victim)
	{
		setRoot(replacement);
		return true;
	}
	return false;
}

Term* System::getRoot() const
{
	return getChild(0);
}

void System::setRoot(Term* t)
{
	setChild(0, t);
}
