#ifndef __INTNUMBER_CLASS__
#define __INTNUMBER_CLASS__

#include <core/terms/Term.hpp>

class IntNumber : public Term<int>
{
	public:
		IntNumber(const int value);
		virtual int getValue() const override;
	private:
		int value_;
};

#endif
