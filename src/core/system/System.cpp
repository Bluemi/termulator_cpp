#include "System.hpp"

#include <core/terms/EmptyTerm.hpp>
#include <core/misc/Debug.hpp>

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

Value System::getValue() const
{
	return getRoot()->getValue();
}

ValueType System::getValueType() const
{
	return getRoot()->getValueType();
}

bool System::isEmpty() const
{
	return getRoot()->isEmptyTerm();
}

void System::addContainer(TermContainer* c)
{
	Term* oldTop = branch_.back();
	TermContainer* oldTopContainer = getLeafContainer();
	if (!oldTopContainer->replace(oldTop, c))
	{
		Debug::out << "ERROR: System::addContainer(): couldn't replace oldTop with c" << Debug::endl;
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
	if (getLeaf()->isContainer())
	{
		delete t;
		return false;
	}

	Term* oldTop = getLeaf();
	TermContainer* c = getLeafContainer();
	if (c->replace(oldTop, t))
	{
		delete oldTop;
		return true;
	}
	else
	{
		Debug::out << Debug::error << "System::addChild(): couldn't replace oldTop with t" << Debug::endl;
		delete t;
		return false;
	}
}

bool System::containerSelected() const
{
	return !getLeaf()->isContainer();
}

void System::selectUp()
{
	if (branch_.size() > 1)
		branch_.pop_back();
}

void System::selectDown()
{
	if (branch_.back()->isContainer())
	{
		TermContainer* t = dynamic_cast<TermContainer*>(branch_.back());
		branch_.push_back(t->getChild(0));
	}
}

void System::selectLeft()
{
	TermContainer* c = getLeafContainer();
	Term* t = c->getLefterChild(getLeaf());
	if (t != nullptr)
	{
		branch_.pop_back();
		branch_.push_back(t);
	}
	else
	{
		Debug::out << Debug::warn << "System::selectLeft(): lefterChild returns nullptr" << Debug::endl;
	}
}

void System::selectRight()
{
	TermContainer* c = getLeafContainer();
	Term* t = c->getRighterChild(getLeaf());
	if (t != nullptr)
	{
		branch_.pop_back();
		branch_.push_back(t);
	}
	else
	{
		Debug::out << Debug::warn << "System::selectRight(): righterChild returns nullptr" << Debug::endl;
	}
}

Representation System::getRepresentation(Representable* markedRepresentable) const
{
	if (markedRepresentable != nullptr)
	{
		Debug::out << Debug::warn << "System::getRepresentation(): markedRepresentable != nullptr" << Debug::endl;
	}
	return getRoot()->getRepresentation(getLeaf());
}

Term* System::getLeaf() const
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

Term* System::getRoot() const
{
	return getChild(0);
}

bool System::replace(Term* victim, Term* replacement)
{
	if (getRoot() == victim)
	{
		setRoot(replacement);
		branch_[0] = replacement;
		return true;
	}
	return false;
}

void System::setRoot(Term* t)
{
	setChild(0, t);
}
