#include "TermContainer.hpp"

#include <iostream>

#include "EmptyTerm.hpp"

TermContainer::TermContainer(unsigned int size)
	: MISSING_ARGUMENT("_"), size_(size)
{
	terms_ = (Term**) (::operator new(size_*(sizeof(Term**))));
	for (unsigned int i = 0; i < size_; i++)
	{
		terms_[i] = new EmptyTerm();
	}
}

TermContainer::~TermContainer()
{
	for (unsigned int i = 0; i < size_; i++)
	{
		delete terms_[i];
		terms_[i] = nullptr;
	}
	::operator delete(terms_);
}

bool TermContainer::validIndex(const unsigned int index) const
{
	return (index >= 0) && (index < size_);
}

bool TermContainer::isContainer() const
{
	return true;
}

bool TermContainer::hasValue() const
{
	for (unsigned int i = 0; i < size_; i++)
	{
		if (!getChild(i)->hasValue())
		{
			return false;
		}
	}
	return true;
}

std::string TermContainer::getString() const
{
	std::string s = "";
	for (unsigned int i = 0; i < size_; i++)
	{
		s += getChild(i)->getString();
		if (i != (size_-1))
		{
			s += getLinkSign();
		}
	}
	return s;
}

unsigned int TermContainer::getChildSize() const
{
	return size_;
}

Term* TermContainer::getChild(const unsigned int index) const
{
	if (validIndex(index))
	{
		return terms_[index];
	}
	return nullptr;
}

Term* TermContainer::setChild(const unsigned int index, Term* t)
{
	if (t == nullptr)
	{
		std::cout << "ERROR: TermContainer::setChild(): t == nullptr" << std::endl;
		return nullptr;
	}
	if (validIndex(index))
	{
		Term* oldTerm = terms_[index];
		terms_[index] = t;
		return oldTerm;
	}
	return nullptr;
}

bool TermContainer::addChild(Term* t)
{
	if (t == nullptr)
	{
		std::cout << "ERROR: TermContainer::addChild(): t == nullptr" << std::endl;
		return false;
	}
	const unsigned int index = getFirstEmptySlot();
	if (validIndex(index))
	{
		terms_[index] = t;
		return true;
	}
	return false;
}

bool TermContainer::replace(Term* victim, Term* replacement)
{
	for (unsigned int i = 0; i < size_; i++)
	{
		if (terms_[i] == victim)
		{
			terms_[i] = replacement;
			return true;
		}
	}
	return false;
}

bool TermContainer::isEmpty() const
{
	for (unsigned int i = 0; i < size_; i++)
	{
		if (!terms_[i]->isEmptyTerm())
		{
			return false;
		}
	}
	return true;
}

bool TermContainer::isSlotEmpty(const unsigned int i) const
{
	if (validIndex(i))
	{
		return terms_[i]->isEmptyTerm();
	}
	return false;
}

unsigned int TermContainer::getFirstEmptySlot() const
{
	for (unsigned int i = 0; i < size_; i++)
	{
		if (isSlotEmpty(i))
		{
			return i;
		}
	}
	return -1;
}
