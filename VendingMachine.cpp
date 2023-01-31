#pragma once
#include "Misc.h"
#include "SnackSlot.h"
#include "VendingMachine.h"

VendingMachine::VendingMachine(unsigned const slotsCount, unsigned const slotSnacksCount)
{

	SlotsCount = slotsCount;

	Slots = new SnackSlots::SnackSlot * [SlotsCount];

	for (unsigned i = 0; i < SlotsCount; i++) {
		Slots[i] = new SnackSlots::SnackSlot(slotSnacksCount);
		Slots[i]->SlotIndex = i;
	}
	Misc::SendDebugMsg("Конструктор VendingMachine с готовыми слотами");
}

VendingMachine::VendingMachine(unsigned slotsCount)
{
	SlotsCount = slotsCount;
	Slots = new SnackSlots::SnackSlot * [SlotsCount];
	for (unsigned i = 0; i < SlotsCount; i++) {
		Slots[i] = nullptr;
	}
	Misc::SendDebugMsg("Конструктор VendingMachine без слотов");
}

VendingMachine::~VendingMachine()
{
	for (unsigned i = 0; i < SlotsCount; i++) {
		delete Slots[i];
	}
	delete[] Slots;
	Misc::SendDebugMsg("Destructor VendingMachine");
}

unsigned VendingMachine::getSlotsCount()
{
	return SlotsCount;
}

void VendingMachine::getEmptySlotsCount()
{
	std::cout << "Количество пустых слотов: ";
	int count = 0;
	for (unsigned i = 0; i < SlotsCount; i++) {
		if ((Slots[i] != nullptr) && (Slots[i]->statuses & SnackSlots::empty)) count++;
	}
	std::cout << count << std::endl;
}

void VendingMachine::getEmptySlotsCells()
{
	std::cout << "Количество пустых ячеек для слотов: ";
	int count = 0;
	for (unsigned i = 0; i < SlotsCount; i++) {
		if (Slots[i] == nullptr) count++;
	}
	std::cout << count << std::endl;
}

void VendingMachine::addSlot(SnackSlots::SnackSlot slot)
{
	for (unsigned i = 0; i < SlotsCount; i++) {
		if (Slots[i] == nullptr) {
			Slots[i] = new SnackSlots::SnackSlot(slot, slot.getSnacksMaxCount());
			Slots[i]->SlotIndex = i;
			break;
		}
	}
}

Snacks::Snack* VendingMachine::Sale(unsigned machineSlot, unsigned snackIndex, unsigned* customerWallet, std::string* failMessage)
{
	if (machineSlot > SlotsCount - 1 || snackIndex > Slots[machineSlot]->getSnacksMaxCount() - 1) {
		*failMessage = "Вы выбрали ячейку за пределом допустимых диапазонов.";
		return nullptr;
	}
	if (Slots[machineSlot]->Snacks[snackIndex] == nullptr) {
		*failMessage = "Вы выбрали ячейку с отсутствующим снеком.";
		return nullptr;
	}
	if (Slots[machineSlot]->statuses & SnackSlots::empty) {
		*failMessage = "\nСлот пустой.";
		return nullptr;
	}

	int newBalance = *customerWallet - Slots[machineSlot]->Snacks[snackIndex]->getPrice();

	if (newBalance < 0) {
		std::string newBalance_s;
		std::stringstream ss;
		ss << ~(newBalance - 1);
		ss >> newBalance_s;
		*failMessage = "Вам не хватает " + newBalance_s + " монет.";
		return nullptr;
	}
	Snacks::Snack* customerSnack = SnackSlots::SnackSlot::NewSnack(*Slots[machineSlot]->Snacks[snackIndex]);
	Slots[machineSlot]->DeleteSnacks(snackIndex);
	customerSnack->statuses = (Snacks::Statuses)((customerSnack->statuses | Snacks::Statuses::sold) & ~(Snacks::Statuses::sale | Snacks::Statuses::inSnackSlot));
	*customerWallet -= customerSnack->getPrice();
	return customerSnack;
}