#ifndef __TERM_CLASS__
#define __TERM_CLASS__

template<typename OUT>
class Term
{
	public:
		Term();
		virtual OUT getValue() const = 0;
};

#endif
