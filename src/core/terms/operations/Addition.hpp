#ifndef __ADDITION_CLASS__
#define __ADDITION_CLASS__

#include "Operation.hpp"

class Addition : public Operation<2>
{
	public:
		Addition();
		virtual Data getValue() const override;
	protected:
		virtual std::string getLinkSign() const override;
};

#endif
