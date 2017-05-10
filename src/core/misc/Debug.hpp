#ifndef __DEBUG_CLASS__
#define __DEBUG_CLASS__

#include <vector>
#include <string>

#define NOTE_COLOR FYELLOW
#define ERROR_COLOR FRED
#define DEFAULT_COLOR "\u001B[0m"

#define FBLACK "\u001B[30m"
#define FRED "\u001B[31m"
#define FGREEN "\u001B[32m"
#define FYELLOW "\u001B[33m"
#define FBLUE "\u001B[34m"
#define FPURPLE "\u001B[35m"
#define FCYAN "\u001B[36m"

namespace Debug
{
	enum Tag { endl, error, note };
	class DebugClass
	{
		public:
			DebugClass();
			~DebugClass();

			DebugClass& operator<<(int i);
			DebugClass& operator<<(float f);
			DebugClass& operator<<(std::string s);
			DebugClass& operator<<(const Debug::Tag tag);
		private:
			std::vector<std::string> strings_;
	};
	static DebugClass out;
}


#endif
