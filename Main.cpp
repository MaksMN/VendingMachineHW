#pragma once
#include <iostream>
#include <string>
#include "Misc.h"
#include "Snack.h"
#include "SnackSlot.h"
#include "VendingMachine.h"

int main() {
	setlocale(LC_ALL, "");

	/*Демонстрация работы вендинговой машины.*/
	// Машина состоит из нескольких слотов в которые помещаются снеки.
	// Каждый слот вмещает в себя ограниченное количество снеков.
	// В один слот можно помещать разные снеки.

	/*Принцип работы классов*/
	// Класс VendingMachine хранит в себе массив слотов.
	// Каждый слот хранит в себе массив снеков.
	// У слота есть несколько состояний: полный, неполный, пустой, выдвинут & вставлен в машину.
	// У снеков есть несколько состояний: null, продается, продан, съеден, в слоте.
	// Состояния слота и снеков реализованы через перечисления (enum).
	// Слоты и снеки имеют поля и методы для операций над ними: добавление, удаление, вывод статистической информации.

	std::cout << "*** ПРИМЕРЫ РАБОТЫ С КЛАССАМИ ***" << std::endl;

	// Создание вендинговой машины. В аргументах указывается количество слотов и количество снеков в одном слоте.
	VendingMachine* Machine = new VendingMachine(3, 6);
	std::cout << "Создана вендинговая машина:" << "\nСлотов: " << Machine->getSlotsCount() << std::endl;

	// Этот метод выводит количество пустых слотов для снеков
	Machine->getEmptySlotsCount();

	// Создание снека. В аргументах указывается название, цена, калорийность.
	Snacks::Snack snickers("Snickers", 40, 487);
	// По умолчанию у снека статус = null. Перед помещением снека в слот машины можно задать ему статусы: В слоте | Продается &~null
	snickers.statuses = (Snacks::Statuses)((snickers.statuses | Snacks::Statuses::inSnackSlot | Snacks::Statuses::sale) & ~Snacks::Statuses::null);
	std::cout << "\nСоздан снек: " << snickers.Name << " цена: " << snickers.getPrice() << std::endl;

	/*К слотам машины можно обращаться по их индексу.*/
	// Machine->Slots[0]->Methods();
	// Machine->Slots[0]->Fields;

	/*В слотах реализованы следующие методы:*/

	// Метод AddSnacks заполняет слот указанным количеством снеков. 
	// Если указанное число превышает вместимость слота - слот будет заполнен до конца.
	Machine->Slots[0]->AddSnacks(5, snickers);
	std::cout << "\nВ слот №0 добавлено 5 снеков " << snickers.Name << std::endl;

	// Создадим новый снек и полностью заполним другой слот
	Snacks::Snack bounty("Bounty", 50, 487);
	bounty.statuses = (Snacks::Statuses)((bounty.statuses | Snacks::Statuses::inSnackSlot | Snacks::Statuses::sale) & ~Snacks::Statuses::null);
	std::cout << "\nСоздан снек: " << bounty.Name << " цена: " << bounty.getPrice() << std::endl;

	// AddSnacks имеет перегрузку. Если его вызвать без указания количества снеков - слот будет заполнен до конца.
	Machine->Slots[1]->AddSnacks(bounty);
	std::cout << "\nВ слот №1 полностью заполнен снеками " << bounty.Name << std::endl;

	// Этот метод выводит информацию о количестве снеков и их список в слоте.

	std::cout << "\nИнформация о слотах после заполнения их снеками " << snickers.Name << ", " << bounty.Name << std::endl;

	Machine->getEmptySlotsCount();
	Machine->Slots[0]->SlotInfo();
	Machine->Slots[1]->SlotInfo();

	// Метод DeleteSnacks удаляет снеки из слота. Имеет одну перегрузку.

	// Удаляет снек с указанным индексом.
	Machine->Slots[0]->DeleteSnacks(1);
	std::cout << "\nИнформация о слоте №0 после удаления снека с индексом 1. Он отсутствует в списке ниже.";
	Machine->Slots[0]->SlotInfo();

	// Если вызвать метод DeleteSnacks без аргументов - удалит все снеки в слоте.
	Machine->Slots[1]->DeleteSnacks();
	std::cout << "\nИнформация о слоте №1 после удаления всех снеков.";
	Machine->Slots[1]->SlotInfo();

	// В классе SnackSlot реализованы все необходимые деструкторы и освобождение динамической памяти при удалении снека.

	// К снекам можно обратиться по их индексу в слоте. 
	std::cout << "\nИнформация о снеке в слоте №0.";
	std::cout << "\nНазвание первого снека в слоте 0: " << Machine->Slots[0]->Snacks[0]->Name << std::endl;
	std::cout << "Цена первого снека в слоте 0 = " << Machine->Slots[0]->Snacks[0]->getPrice() << std::endl;
	std::cout << "Калорийность первого снека в слоте 0 = " << Machine->Slots[0]->Snacks[0]->getCalories() << std::endl;

	// изменим цену первого снека в первом слоте
	Machine->Slots[0]->Snacks[0]->setPrice(25);
	std::cout << "\nИнформация о слоте №0 после изменения цены снека с индексом 0.";
	Machine->Slots[0]->SlotInfo();

	// При удалении объекта класса VendingMachine
	// его деструктор освобождает всю динамическую память занятую слотами и снеками.
	// Достаточно просто удалить VendingMachine.
	// Если переменная  Misc::ShowDebug = true, будет выводиться сообщение о срабатывании конструкторов и деструкторов.
	delete Machine;

	std::cout <<
		"\nТак же в классах реализована возможность собирать слоты отдельно от машины и вставлять их в машину"
		"\n\nСоздадим слоты с разным количеством ячеек для снеков,"
		"\nдобавим снеки, "
		"\nодин слот оставим пустым";

	SnackSlots::SnackSlot* slot1 = new SnackSlots::SnackSlot(5);
	slot1->SlotIndex = 0;
	slot1->AddSnack(snickers);
	slot1->AddSnack(bounty);

	SnackSlots::SnackSlot* slot2 = new SnackSlots::SnackSlot(8);
	slot2->SlotIndex = 1;
	slot2->AddSnack(bounty);
	slot2->AddSnack(snickers);

	SnackSlots::SnackSlot* slot3 = new SnackSlots::SnackSlot(5);

	std::cout << "\nСоздадим машину под 4 слота. Одна ячейка для слота будет пустой.\n";
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

	/*демонстрация торговли*/

	Machine = new VendingMachine(2, 5);

	//Создание снеков
	Snacks::Snack nuts("Nuts", 45, 555);
	nuts.statuses = (Snacks::Statuses)((nuts.statuses | Snacks::Statuses::inSnackSlot | Snacks::Statuses::sale) & ~Snacks::Statuses::null);
	Snacks::Snack picnic("Picnic", 55, 487);
	picnic.statuses = (Snacks::Statuses)((picnic.statuses | Snacks::Statuses::inSnackSlot | Snacks::Statuses::sale) & ~Snacks::Statuses::null);

	//Заполнение всех слотов снеками
	Machine->Slots[0]->AddSnacks(nuts);
	Machine->Slots[1]->AddSnacks(picnic);

	unsigned customerWallet = 100;
	unsigned bagSnacksCount = 5;
	unsigned bagAddSnacksCount = 0;
	int machineSlot, snackIndex;
	std::string failMessage = "";
	bool requestMoney = true;

	std::cout << "\n\n*** МЕНЮ ТОРГОВЛИ ***" << std::endl;

	customerWallet = Misc::GetUnsignedNonZeroNum(1, 1000, "\nСколько у вас денег(1 - 1000)?\n", "Количество денег должно быть положительным числом больше нуля (1 - 1000).\nСколько у вас денег?\n");
	bagSnacksCount = Misc::GetUnsignedNonZeroNum(1, 10, "\nСколько снеков помещается у вас в сумке (1 - 10)?\n",
		"Количество снеков в сумке должно быть положительным числом больше нуля (1 - 10).\nСколько снеков помещается у вас в сумке?\n");

	Snacks::Snack** customerSlot = new Snacks::Snack * [bagSnacksCount];
	for (unsigned i = 0; i < bagSnacksCount; i++) {
		customerSlot[i] = nullptr;
	}

	do {
		std::cout << "\n\n*** МЕНЮ ТОРГОВЛИ ***" << std::endl;
		std::cout << "\n\nСписки товара в слотах." << std::endl;

		Machine->Slots[0]->SlotInfo();
		Machine->Slots[1]->SlotInfo();

		if (failMessage != "") std::cout << failMessage << std::endl;
		failMessage = "";

		std::cout << "\nУ вас есть " << customerWallet << " монет." << std::endl;
		std::cout << "В вашу сумку помещается " << bagSnacksCount - bagAddSnacksCount << " снеков." << std::endl;
		std::cout << "\nСнеки в вашей сумке:" << std::endl;
		for (unsigned i = 0; i < bagSnacksCount; i++) {
			if (customerSlot[i] == nullptr) { std::cout << "Пусто" << std::endl; }
			else { std::cout << customerSlot[i]->Name << std::endl; }
		}

		std::cout << "\nВыше список слотов и снеков в них. Выбирайте номера слотов снеков из этих списков." << std::endl;
		std::cout << "Купленные снеки будут исчезать из этих списков. И появляться в вашей сумке." << std::endl;
		std::cout << "\nУкажите номер слота (0 - " << Machine->getSlotsCount() - 1 << ") (-1 - выход)" << std::endl;
		std::cin >> machineSlot;
		if (machineSlot < 0) {
			break;
		}
		std::cout << "\nУкажите номер снека в слоте (-1 - выход)" << std::endl;
		std::cin >> snackIndex;

		if (snackIndex < 0) {
			break;
		}

		if (bagAddSnacksCount == bagSnacksCount) {
			std::cout << "В сумке больше нет места." << std::endl;
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