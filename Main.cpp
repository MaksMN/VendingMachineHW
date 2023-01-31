#pragma once
#include <iostream>
#include <string>
#include "Misc.h"
#include "Snack.h"
#include "SnackSlot.h"
#include "VendingMachine.h"

int main() {
	setlocale(LC_ALL, "");

	/*������������ ������ ����������� ������.*/
	// ������ ������� �� ���������� ������ � ������� ���������� �����.
	// ������ ���� ������� � ���� ������������ ���������� ������.
	// � ���� ���� ����� �������� ������ �����.

	/*������� ������ �������*/
	// ����� VendingMachine ������ � ���� ������ ������.
	// ������ ���� ������ � ���� ������ ������.
	// � ����� ���� ��������� ���������: ������, ��������, ������, �������� & �������� � ������.
	// � ������ ���� ��������� ���������: null, ���������, ������, ������, � �����.
	// ��������� ����� � ������ ����������� ����� ������������ (enum).
	// ����� � ����� ����� ���� � ������ ��� �������� ��� ����: ����������, ��������, ����� �������������� ����������.

	std::cout << "*** ������� ������ � �������� ***" << std::endl;

	// �������� ����������� ������. � ���������� ����������� ���������� ������ � ���������� ������ � ����� �����.
	VendingMachine* Machine = new VendingMachine(3, 6);
	std::cout << "������� ����������� ������:" << "\n������: " << Machine->getSlotsCount() << std::endl;

	// ���� ����� ������� ���������� ������ ������ ��� ������
	Machine->getEmptySlotsCount();

	// �������� �����. � ���������� ����������� ��������, ����, ������������.
	Snacks::Snack snickers("Snickers", 40, 487);
	// �� ��������� � ����� ������ = null. ����� ���������� ����� � ���� ������ ����� ������ ��� �������: � ����� | ��������� &~null
	snickers.statuses = (Snacks::Statuses)((snickers.statuses | Snacks::Statuses::inSnackSlot | Snacks::Statuses::sale) & ~Snacks::Statuses::null);
	std::cout << "\n������ ����: " << snickers.Name << " ����: " << snickers.getPrice() << std::endl;

	/*� ������ ������ ����� ���������� �� �� �������.*/
	// Machine->Slots[0]->Methods();
	// Machine->Slots[0]->Fields;

	/*� ������ ����������� ��������� ������:*/

	// ����� AddSnacks ��������� ���� ��������� ����������� ������. 
	// ���� ��������� ����� ��������� ����������� ����� - ���� ����� �������� �� �����.
	Machine->Slots[0]->AddSnacks(5, snickers);
	std::cout << "\n� ���� �0 ��������� 5 ������ " << snickers.Name << std::endl;

	// �������� ����� ���� � ��������� �������� ������ ����
	Snacks::Snack bounty("Bounty", 50, 487);
	bounty.statuses = (Snacks::Statuses)((bounty.statuses | Snacks::Statuses::inSnackSlot | Snacks::Statuses::sale) & ~Snacks::Statuses::null);
	std::cout << "\n������ ����: " << bounty.Name << " ����: " << bounty.getPrice() << std::endl;

	// AddSnacks ����� ����������. ���� ��� ������� ��� �������� ���������� ������ - ���� ����� �������� �� �����.
	Machine->Slots[1]->AddSnacks(bounty);
	std::cout << "\n� ���� �1 ��������� �������� ������� " << bounty.Name << std::endl;

	// ���� ����� ������� ���������� � ���������� ������ � �� ������ � �����.

	std::cout << "\n���������� � ������ ����� ���������� �� ������� " << snickers.Name << ", " << bounty.Name << std::endl;

	Machine->getEmptySlotsCount();
	Machine->Slots[0]->SlotInfo();
	Machine->Slots[1]->SlotInfo();

	// ����� DeleteSnacks ������� ����� �� �����. ����� ���� ����������.

	// ������� ���� � ��������� ��������.
	Machine->Slots[0]->DeleteSnacks(1);
	std::cout << "\n���������� � ����� �0 ����� �������� ����� � �������� 1. �� ����������� � ������ ����.";
	Machine->Slots[0]->SlotInfo();

	// ���� ������� ����� DeleteSnacks ��� ���������� - ������ ��� ����� � �����.
	Machine->Slots[1]->DeleteSnacks();
	std::cout << "\n���������� � ����� �1 ����� �������� ���� ������.";
	Machine->Slots[1]->SlotInfo();

	// � ������ SnackSlot ����������� ��� ����������� ����������� � ������������ ������������ ������ ��� �������� �����.

	// � ������ ����� ���������� �� �� ������� � �����. 
	std::cout << "\n���������� � ����� � ����� �0.";
	std::cout << "\n�������� ������� ����� � ����� 0: " << Machine->Slots[0]->Snacks[0]->Name << std::endl;
	std::cout << "���� ������� ����� � ����� 0 = " << Machine->Slots[0]->Snacks[0]->getPrice() << std::endl;
	std::cout << "������������ ������� ����� � ����� 0 = " << Machine->Slots[0]->Snacks[0]->getCalories() << std::endl;

	// ������� ���� ������� ����� � ������ �����
	Machine->Slots[0]->Snacks[0]->setPrice(25);
	std::cout << "\n���������� � ����� �0 ����� ��������� ���� ����� � �������� 0.";
	Machine->Slots[0]->SlotInfo();

	// ��� �������� ������� ������ VendingMachine
	// ��� ���������� ����������� ��� ������������ ������ ������� ������� � �������.
	// ���������� ������ ������� VendingMachine.
	// ���� ����������  Misc::ShowDebug = true, ����� ���������� ��������� � ������������ ������������� � ������������.
	delete Machine;

	std::cout <<
		"\n��� �� � ������� ����������� ����������� �������� ����� �������� �� ������ � ��������� �� � ������"
		"\n\n�������� ����� � ������ ����������� ����� ��� ������,"
		"\n������� �����, "
		"\n���� ���� ������� ������";

	SnackSlots::SnackSlot* slot1 = new SnackSlots::SnackSlot(5);
	slot1->SlotIndex = 0;
	slot1->AddSnack(snickers);
	slot1->AddSnack(bounty);

	SnackSlots::SnackSlot* slot2 = new SnackSlots::SnackSlot(8);
	slot2->SlotIndex = 1;
	slot2->AddSnack(bounty);
	slot2->AddSnack(snickers);

	SnackSlots::SnackSlot* slot3 = new SnackSlots::SnackSlot(5);

	std::cout << "\n�������� ������ ��� 4 �����. ���� ������ ��� ����� ����� ������.\n";
	Machine = new VendingMachine(4);
	Machine->addSlot(*slot1);
	Machine->addSlot(*slot2);
	Machine->addSlot(*slot3);
	int a = slot1->SlotIndex;
	Machine->getEmptySlotsCount();
	Machine->getEmptySlotsCells();
	Machine->Slots[0]->SlotInfo();
	Machine->Slots[1]->SlotInfo();

	delete Machine;

	/*������������ ��������*/

	Machine = new VendingMachine(2, 5);

	//�������� ������
	Snacks::Snack nuts("Nuts", 45, 555);
	nuts.statuses = (Snacks::Statuses)((nuts.statuses | Snacks::Statuses::inSnackSlot | Snacks::Statuses::sale) & ~Snacks::Statuses::null);
	Snacks::Snack picnic("Picnic", 55, 487);
	picnic.statuses = (Snacks::Statuses)((picnic.statuses | Snacks::Statuses::inSnackSlot | Snacks::Statuses::sale) & ~Snacks::Statuses::null);

	//���������� ���� ������ �������
	Machine->Slots[0]->AddSnacks(nuts);
	Machine->Slots[1]->AddSnacks(picnic);

	unsigned customerWallet = 100;
	unsigned bagSnacksCount = 5;
	unsigned bagAddSnacksCount = 0;
	int machineSlot, snackIndex;
	std::string failMessage = "";
	bool requestMoney = true;

	std::cout << "\n\n*** ���� �������� ***" << std::endl;

	customerWallet = Misc::GetUnsignedNonZeroNum(1, 1000, "\n������� � ��� �����(1 - 1000)?\n", "���������� ����� ������ ���� ������������� ������ ������ ���� (1 - 1000).\n������� � ��� �����?\n");
	bagSnacksCount = Misc::GetUnsignedNonZeroNum(1, 10, "\n������� ������ ���������� � ��� � ����� (1 - 10)?\n",
		"���������� ������ � ����� ������ ���� ������������� ������ ������ ���� (1 - 10).\n������� ������ ���������� � ��� � �����?\n");

	Snacks::Snack** customerSlot = new Snacks::Snack * [bagSnacksCount];
	for (unsigned i = 0; i < bagSnacksCount; i++) {
		customerSlot[i] = nullptr;
	}

	do {
		std::cout << "\n\n*** ���� �������� ***" << std::endl;
		std::cout << "\n\n������ ������ � ������." << std::endl;

		Machine->Slots[0]->SlotInfo();
		Machine->Slots[1]->SlotInfo();

		if (failMessage != "") std::cout << failMessage << std::endl;
		failMessage = "";

		std::cout << "\n� ��� ���� " << customerWallet << " �����." << std::endl;
		std::cout << "� ���� ����� ���������� " << bagSnacksCount - bagAddSnacksCount << " ������." << std::endl;
		std::cout << "\n����� � ����� �����:" << std::endl;
		for (unsigned i = 0; i < bagSnacksCount; i++) {
			if (customerSlot[i] == nullptr) { std::cout << "�����" << std::endl; }
			else { std::cout << customerSlot[i]->Name << std::endl; }
		}

		std::cout << "\n���� ������ ������ � ������ � ���. ��������� ������ ������ ������ �� ���� �������." << std::endl;
		std::cout << "��������� ����� ����� �������� �� ���� �������. � ���������� � ����� �����." << std::endl;
		std::cout << "\n������� ����� ����� (0 - " << Machine->getSlotsCount() - 1 << ") (-1 - �����)" << std::endl;
		std::cin >> machineSlot;
		if (machineSlot < 0) {
			break;
		}
		std::cout << "\n������� ����� ����� � ����� (-1 - �����)" << std::endl;
		std::cin >> snackIndex;

		if (snackIndex < 0) {
			break;
		}

		if (bagAddSnacksCount == bagSnacksCount) {
			std::cout << "� ����� ������ ��� �����." << std::endl;
			break;
		}

		customerSlot[bagAddSnacksCount] = Machine->Sale(machineSlot, snackIndex, &customerWallet, &failMessage);
		if (customerSlot[bagAddSnacksCount] != nullptr) {
			bagAddSnacksCount++;
		}
	} while (1);
	for (unsigned i = 0; i < bagSnacksCount; i++) {
		delete customerSlot[i];
	}
	delete[] customerSlot;
	delete Machine;
	return 0;
}