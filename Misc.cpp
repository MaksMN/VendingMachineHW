#include "Misc.h"

unsigned Misc::GetUnsignedNonZeroNum(std::string message, std::string warning)
{
	unsigned num;
	std::cout << message;
	std::cin >> num;
	CinClear(&num);
	while (num <= 0) {
		std::cout << std::endl << warning;
		std::cin >> num;
	}
	return num;
}

unsigned Misc::GetUnsignedNonZeroNum(unsigned start, unsigned end, std::string message, std::string warning)
{
	unsigned num;
	std::cout << message;
	std::cin >> num;
	CinClear(&num);
	while (num <= 0 || num < start || num > end) {
		std::cout << std::endl << warning;
		std::cin >> num;
	}
	return num;
}

unsigned Misc::GetUnsignedNonZeroNum(unsigned num, std::string warning)
{
	while (num <= 0) {
		std::cout << std::endl << warning;
		std::cin >> num;
	}
	return num;
}

unsigned Misc::GetUnsignedNonZeroNum(unsigned num, unsigned start, unsigned end, std::string warning)
{
	while (num <= 0 || num < start || num > end) {
		std::cout << std::endl << warning;
		std::cin >> num;
	}
	return num;
}

void Misc::SendMessage(std::string msgtext)
{
	std::cout << msgtext << std::endl;
}

void Misc::SendDebugMsg(std::string message)
{
	if (ShowDebug) {
		std::cout << message << std::endl;
	}
}

void Misc::CinClear(unsigned* num) {
	if (std::cin.fail()) { *num = 0; }
	std::cin.clear(); while (std::cin.get() != '\n');
}