#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Misc.h"
#include "SnackSlot.h"

class VendingMachine
{
	unsigned SlotsCount; // ���������� ������	
public:

	SnackSlots::SnackSlot** Slots;

	/// <summary>
	/// ������� ������ �� ������������ �������.
	/// </summary>
	/// <param name="slotsCount">���������� ������</param>
	/// <param name="slotSnacksCount">���������� ����� � �����</param>
	VendingMachine(unsigned const slotsCount, unsigned const slotSnacksCount);

	/// <summary>
	/// ������� ������ ������ � �������� ��� �����.
	/// ���� ����� ���� ��������� �������� � ��������� � ������
	/// </summary>
	/// <param name="slotsCount"></param>
	VendingMachine(unsigned const slotsCount);

	~VendingMachine();

	unsigned getSlotsCount();

	/// <summary>
	/// �������� ���������� ������ ������
	/// </summary>
	void getEmptySlotsCount();

	/// <summary>
	/// �������� ���������� ����� ��� ������
	/// </summary>
	void getEmptySlotsCells();

	/// <summary>
	/// ��������� ���� � ������
	/// </summary>
	/// <param name="">SnackSlots::SnackSlot</param>
	void addSlot(SnackSlots::SnackSlot slot);

	/// <summary>
	/// ������� ����
	/// </summary>
	/// <param name="machineSlot">����� ����� � ������</param>
	/// <param name="snackIndex">������ ����� � �����</param>
	/// <param name="customerWallet">��������� �� ���������� �������� ����������</param>
	/// <param name="failMessage">��������� �� ���������� � ������� ��������� ��������� � ����� �������</param>
	/// <returns></returns>
	Snacks::Snack* Sale(unsigned machineSlot, unsigned snackIndex, unsigned* customerWallet, std::string* failMessage);
};