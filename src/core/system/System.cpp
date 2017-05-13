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

std::string System::getString() const
{
	return getRoot()->getString();
}

ValueType System::getValueType() const
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
		Debug::out << Debug::error << "System::addChild(): couldn't replace oldTop with t" << Debug::endl;
		delete t;
		return false;
	}
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
		branch_[0] = replacement;
		return true;
	}
	return false;
}

void System::selectUp()
{
	if (!branch_.empty())
		branch_.pop_back();
}

void System::selectDown()
{
	if (branch_.empty())
	{
		branch_.push_back(getRoot());
	}
	if (branch_.back()->isContainer())
	{
		TermContainer* t = dynamic_cast<TermContainer*>(branch_.back());
		branch_.push_back(t->getChild(0));
	}
}

Term* System::getRoot() const
{
	return getChild(0);
}

void System::setRoot(Term* t)
{
	setChild(0, t);
}
