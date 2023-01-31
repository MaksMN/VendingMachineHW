#include "SnackSlot.h"
namespace SnackSlots {

	SnackSlot::SnackSlot(unsigned snacksMaxCount)
	{
		SnacksMaxCount = snacksMaxCount;
		Snacks = new Snacks::Snack * [SnacksMaxCount];
		for (unsigned i = 0; i < SnacksMaxCount; i++) {
			Snacks[i] = nullptr;
		}
		Misc::SendDebugMsg("Конструктор SnackSlot(unsigned snacksMaxCount)");
	}

	SnackSlot::SnackSlot()
	{
		SnacksMaxCount = 1;
		Snacks = new Snacks::Snack * [1];
		Misc::SendDebugMsg("Конструктор SnackSlot()");
	}

	SnackSlot::SnackSlot(SnackSlot& oldSlot, unsigned snacksMaxCount)
	{
		SnacksMaxCount = snacksMaxCount;
		Snacks = new Snacks::Snack * [snacksMaxCount];
		for (unsigned i = 0; i < SnacksMaxCount; i++) {
			if (oldSlot.Snacks[i] != nullptr) {
				Snacks[i] = NewSnack(*oldSlot.Snacks[i]);
			}
			else {
				Snacks[i] = nullptr;
			}
		}
		this->statuses = oldSlot.statuses;
		this->SnacksQuantity = oldSlot.SnacksQuantity;
		Misc::SendDebugMsg("Конструктор SnackSlot(SnackSlot& oldSlot, unsigned snacksMaxCount)");
	}

	SnackSlot::~SnackSlot()
	{
		for (unsigned i = 0; i < SnacksMaxCount; i++) {
			delete Snacks[i];
		}
		Misc::SendDebugMsg("Destructor SnackSlot");
	}

	void SnackSlot::AddSnacks(unsigned quantity, Snacks::Snack snack)
	{
		if (Statuses::full & statuses) {
			Misc::SendMessage("Слот полностью заполнен. Удалите или продайте снеки чтобы добавлять новые.");
			return;
		}
		if (quantity + SnacksQuantity >= SnacksMaxCount) {
			Misc::SendMessage("Превышение вместимости. Слот будет заполнен до конца.");
		}
		unsigned q = 0;
		for (unsigned i = 0; i < SnacksMaxCount; i++) {
			if (Snacks[i] == nullptr) {
				Snacks[i] = NewSnack(snack);
				q++;
				SnacksQuantity++;
			}
			if (q == quantity || SnacksQuantity == SnacksMaxCount) break;
		}
		updateStatuses();
	}

	void SnackSlot::AddSnacks(Snacks::Snack snack)
	{
		for (unsigned i = 0; i < SnacksMaxCount; i++) {
			if (Snacks[i] == nullptr) {
				Snacks[i] = NewSnack(snack);
				SnacksQuantity++;
			}
			if (SnacksQuantity == SnacksMaxCount) break;
		}
		updateStatuses();
	}

	void SnackSlot::AddSnack(Snacks::Snack snack)
	{
		AddSnacks(1, snack);
	}

	void SnackSlot::updateStatuses() {
		if (SnacksQuantity == SnacksMaxCount) statuses = (Statuses)((statuses | Statuses::full) & ~(Statuses::incomplete | Statuses::empty));
		else if (SnacksQuantity == 0) statuses = (Statuses)((statuses | Statuses::empty) & ~(Statuses::incomplete | Statuses::full));
		else statuses = (Statuses)((statuses | Statuses::incomplete) & ~(Statuses::full | Statuses::empty));
	}

	void SnackSlot::DeleteSnacks(unsigned index)
	{
		delete&* Snacks[index];
		Snacks[index] = nullptr;
		SnacksQuantity--;
		updateStatuses();
	}

	void SnackSlot::DeleteSnacks() {
		for (unsigned i = 0; i < SnacksMaxCount; i++) {
			delete&* Snacks[i];
			Snacks[i] = nullptr;
		}
		SnacksQuantity = 0;
		updateStatuses();
	}

	void SnackSlot::InsertSlot() {
		statuses = (Statuses)((statuses | Statuses::inserted) & ~Statuses::ejected);
	}
	void SnackSlot::EjectSlot() {
		statuses = (Statuses)((statuses | Statuses::ejected) & ~Statuses::inserted);
	}

	unsigned SnackSlot::getSnacksQuantity()
	{
		return SnacksQuantity;
	}

	unsigned SnackSlot::getSnacksMaxCount()
	{
		return SnacksMaxCount;
	}

	void SnackSlot::SlotInfo(bool showSnacks)
	{
		std::cout <<
			"\nСлот №" << SlotIndex <<
			"\nКоличество снеков: " << SnacksQuantity <<
			"\nВместимость: " << SnacksMaxCount <<
			"\nМожно добавить " << getFreeSeats() << " снеков" << std::endl;

		//Вывести список снеков в слоте
		if (showSnacks && !(statuses & Statuses::empty)) {
			Misc::SendMessage("Полный список снеков");

			for (unsigned i = 0; i < SnacksMaxCount; i++) {
				if (Snacks[i] != nullptr) {
					std::cout << "[" << i << "] " <<
						Snacks[i]->Name <<
						" Цена: " << Snacks[i]->getPrice() <<
						" Калорийность: " << Snacks[i]->getCalories() <<
						std::endl;
				}
			}
			std::cout << std::endl;
		}
	}
	unsigned SnackSlot::getFreeSeats()
	{
		return SnacksMaxCount - getSnacksQuantity();
	}

	Snacks::Snack* SnackSlot::NewSnack(Snacks::Snack snack)
	{
		Snacks::Snack* s = new Snacks::Snack();
		*s = snack;
		return s;
	}
}