#ifndef __ADDITION_CLASS__
#define __ADDITION_CLASS__

#include "Operation.hpp"

class Addition : public Operation
{
	public:
		Addition();
		virtual Value getValue() const override;
	protected:
		virtual std::string getLinkSign() const override;
};

#endif
