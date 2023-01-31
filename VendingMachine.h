#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Misc.h"
#include "SnackSlot.h"

class VendingMachine
{
	unsigned SlotsCount; // Количество слотов	
public:

	SnackSlots::SnackSlot** Slots;

	/// <summary>
	/// Создает машину со вставленными слотами.
	/// </summary>
	/// <param name="slotsCount">Количество слотов</param>
	/// <param name="slotSnacksCount">Количество ячеек в слоте</param>
	VendingMachine(unsigned const slotsCount, unsigned const slotSnacksCount);

	/// <summary>
	/// Создает машину только с ячейками под слоты.
	/// Сами слоты надо создавать отдельно и добавлять в машину
	/// </summary>
	/// <param name="slotsCount"></param>
	VendingMachine(unsigned const slotsCount);

	~VendingMachine();

	unsigned getSlotsCount();

	/// <summary>
	/// Получает количество пустых слотов
	/// </summary>
	void getEmptySlotsCount();

	/// <summary>
	/// Получает количество ячеек без слотов
	/// </summary>
	void getEmptySlotsCells();

	/// <summary>
	/// Добавляет слот в машину
	/// </summary>
	/// <param name="">SnackSlots::SnackSlot</param>
	void addSlot(SnackSlots::SnackSlot slot);

	/// <summary>
	/// Продает снек
	/// </summary>
	/// <param name="machineSlot">Номер слота в машине</param>
	/// <param name="snackIndex">Индекс снека в слоте</param>
	/// <param name="customerWallet">Указатель на переменную кошелька покупателя</param>
	/// <param name="failMessage">Указатель на переменную в которую выводится сообщение о сбоях покупки</param>
	/// <returns></returns>
	Snacks::Snack* Sale(unsigned machineSlot, unsigned snackIndex, unsigned* customerWallet, std::string* failMessage);
};