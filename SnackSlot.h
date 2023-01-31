#pragma once
#include <iostream>
#include <string>
#include "Misc.h"
#include "Snack.h"

namespace SnackSlots {
	enum Statuses {
		ejected = 1,
		inserted = 2,
		full = 4,
		incomplete = 8,
		empty = 16
	};
	class SnackSlot
	{
		unsigned SnacksQuantity = 0;
		unsigned SnacksMaxCount;
		void updateStatuses();

	public:
		Snacks::Snack** Snacks;
		int SlotIndex = 0;
		Statuses statuses = (Statuses)(Statuses::inserted | Statuses::empty);

		SnackSlot(unsigned snacksMaxCount);
		SnackSlot();
		SnackSlot(SnackSlot& obj, unsigned snacksMaxCount);
		~SnackSlot();

		/// <summary>
		/// Заполняет слот указанным количеством снеков.
		/// Ищет первые свободные ячейки.
		/// </summary>
		/// <param name="quantity">Количество добавляемых снеков. Если превышает вместимость, слот будет заполнен до конца</param>
		/// <param name="snack">Объект Snack</param>
		void AddSnacks(unsigned quantity, Snacks::Snack snack);

		/// <summary>
		/// Заполняет все свободные ячейки слота
		/// </summary>
		/// <param name="snack">Объект Snack</param>
		void AddSnacks(Snacks::Snack snack);

		/// <summary>
		/// Добавляет снек в первую свободную ячейку
		/// </summary>
		/// <param name="snack">Объект Snack</param>
		void AddSnack(Snacks::Snack snack);

		/// <summary>
		/// Удаляет снек в ячейке с указанным индексом
		/// </summary>
		/// <param name="index">Индекс снека в слоте</param>
		void DeleteSnacks(unsigned index);

		// Удаляет все ячейки в слоте
		void DeleteSnacks();

		/// <summary>
		/// Вставляет слот в автомат
		/// </summary>
		void InsertSlot();

		/// <summary>
		/// Извлекает слот из автомата
		/// </summary>
		void EjectSlot();

		/// <summary>
		/// Количество снеков в слоте
		/// </summary>
		/// <returns>unsigned</returns>
		unsigned getSnacksQuantity();

		unsigned getSnacksMaxCount();

		/// <summary>
		/// Информация о слоте
		/// </summary>
		/// <param name="showSnacks">Показать список снеков</param>
		void SlotInfo(bool showSnacks = true);

		/// <summary>
		/// Количество свободных ячеек
		/// </summary>
		/// <returns>unsigned</returns>
		unsigned getFreeSeats();

		/// <summary>
		/// Создает динамический объект Snack
		/// </summary>
		/// <param name="snack">Snacks::Snack</param>
		/// <returns>Snacks::Snack</returns>
		static Snacks::Snack* NewSnack(Snacks::Snack snack);
	};
}