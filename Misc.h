#pragma once
#include <iostream>
#include <string>
class Misc
{
public:
	/// <summary>
	/// ����������� ������������� ����� ������ ����
	/// </summary>
	/// <param name="message">����� �������</param>
	/// <param name="warning">����� �������������� ���� ����� �� ������������� ��������</param>
	/// <returns>unsigned</returns>
	static unsigned GetUnsignedNonZeroNum(std::string message, std::string warning);

	/// <summary>
	/// ����������� ������������� ����� ������ ���� �� ��������� �����
	/// </summary>
	/// <param name="start">��������� ����� ���������</param>
	/// <param name="end">�������� ����� ���������</param>
	/// <param name="message">����� �������</param>
	/// <param name="warning">����� �������������� ���� ����� �� ������������� ��������</param>
	/// <returns>unsigned</returns>
	static unsigned GetUnsignedNonZeroNum(unsigned start, unsigned end, std::string message, std::string warning);

	/// <summary>
	/// ��������� ������������� ����� ������ ����
	/// </summary>
	/// <param name="message">����� �������</param>
	/// <param name="warning">����� �������������� ���� ����� �� ������������� ��������</param>
	/// <returns>unsigned</returns>
	static unsigned GetUnsignedNonZeroNum(unsigned num, std::string warning);

	/// <summary>
	/// ��������� ������������� ����� ������ ���� �� ��������� �����
	/// </summary>
	/// <param name="start">��������� ����� ���������</param>
	/// <param name="end">�������� ����� ���������</param>
	/// <param name="message">����� �������</param>
	/// <param name="warning">����� �������������� ���� ����� �� ������������� ��������</param>
	/// <returns>unsigned</returns>
	static unsigned GetUnsignedNonZeroNum(unsigned num, unsigned start, unsigned end, std::string warning);

	/// <summary>
	/// ������� ��������� �� �����
	/// </summary>
	/// <param name="msgtext">string</param>
	static void SendMessage(std::string msgtext);

	/// <summary>
	/// ������� ��������� �� ����� ���� ���������� ShowDebug = true
	/// ����������� ��� ������������ ������������� � ������������.
	/// </summary>
	/// <param name="message">string</param>
	static void SendDebugMsg(std::string message);

private:
	static void CinClear(unsigned* num);
	static const bool ShowDebug = false;
};