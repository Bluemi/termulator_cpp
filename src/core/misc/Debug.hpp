#ifndef __DEBUG_CLASS__
#define __DEBUG_CLASS__

/*

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

class Debug
{
	public:
		enum Tag { endl, error, note };

		static Debug debug;

		Debug();
		~Debug();

		Debug& operator<<(int i);
		Debug& operator<<(float f);
		Debug& operator<<(std::string s);
		Debug& operator<<(const Debug::Tag tag);
	private:

		static Debug instance;
		std::vector<std::string> strings_;
};

Debug Debug::debug;
*/

#endif
