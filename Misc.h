#pragma once
#include <iostream>
#include <string>
class Misc
{
public:
	/// <summary>
	/// «апрашивает положительное число больше нол€
	/// </summary>
	/// <param name="message">“екст запроса</param>
	/// <param name="warning">“екст предупреждени€ если число не соответствует услови€м</param>
	/// <returns>unsigned</returns>
	static unsigned GetUnsignedNonZeroNum(std::string message, std::string warning);

	/// <summary>
	/// «апрашивает положительное число больше нол€ из диапазона чисел
	/// </summary>
	/// <param name="start">Ќачальное число диапазона</param>
	/// <param name="end"> онечное число диапазона</param>
	/// <param name="message">“екст запроса</param>
	/// <param name="warning">“екст предупреждени€ если число не соответствует услови€м</param>
	/// <returns>unsigned</returns>
	static unsigned GetUnsignedNonZeroNum(unsigned start, unsigned end, std::string message, std::string warning);

	/// <summary>
	/// ѕровер€ет положительное число больше нол€
	/// </summary>
	/// <param name="message">“екст запроса</param>
	/// <param name="warning">“екст предупреждени€ если число не соответствует услови€м</param>
	/// <returns>unsigned</returns>
	static unsigned GetUnsignedNonZeroNum(unsigned num, std::string warning);

	/// <summary>
	/// ѕровер€ет положительное число больше нол€ из диапазона чисел
	/// </summary>
	/// <param name="start">Ќачальное число диапазона</param>
	/// <param name="end"> онечное число диапазона</param>
	/// <param name="message">“екст запроса</param>
	/// <param name="warning">“екст предупреждени€ если число не соответствует услови€м</param>
	/// <returns>unsigned</returns>
	static unsigned GetUnsignedNonZeroNum(unsigned num, unsigned start, unsigned end, std::string warning);

	/// <summary>
	/// ¬ыводит сообщение на экран
	/// </summary>
	/// <param name="msgtext">string</param>
	static void SendMessage(std::string msgtext);

	/// <summary>
	/// ¬ыводит сообщение на экран если переменна€ ShowDebug = true
	/// примен€етс€ дл€ тестировани€ конструкторов и деструкторов.
	/// </summary>
	/// <param name="message">string</param>
	static void SendDebugMsg(std::string message);

private:
	static void CinClear(unsigned* num);
	static const bool ShowDebug = false;
};