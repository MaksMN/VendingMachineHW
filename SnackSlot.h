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
		/// ��������� ���� ��������� ����������� ������.
		/// ���� ������ ��������� ������.
		/// </summary>
		/// <param name="quantity">���������� ����������� ������. ���� ��������� �����������, ���� ����� �������� �� �����</param>
		/// <param name="snack">������ Snack</param>
		void AddSnacks(unsigned quantity, Snacks::Snack snack);

		/// <summary>
		/// ��������� ��� ��������� ������ �����
		/// </summary>
		/// <param name="snack">������ Snack</param>
		void AddSnacks(Snacks::Snack snack);

		/// <summary>
		/// ��������� ���� � ������ ��������� ������
		/// </summary>
		/// <param name="snack">������ Snack</param>
		void AddSnack(Snacks::Snack snack);

		/// <summary>
		/// ������� ���� � ������ � ��������� ��������
		/// </summary>
		/// <param name="index">������ ����� � �����</param>
		void DeleteSnacks(unsigned index);

		// ������� ��� ������ � �����
		void DeleteSnacks();

		/// <summary>
		/// ��������� ���� � �������
		/// </summary>
		void InsertSlot();

		/// <summary>
		/// ��������� ���� �� ��������
		/// </summary>
		void EjectSlot();

		/// <summary>
		/// ���������� ������ � �����
		/// </summary>
		/// <returns>unsigned</returns>
		unsigned getSnacksQuantity();

		unsigned getSnacksMaxCount();

		/// <summary>
		/// ���������� � �����
		/// </summary>
		/// <param name="showSnacks">�������� ������ ������</param>
		void SlotInfo(bool showSnacks = true);

		/// <summary>
		/// ���������� ��������� �����
		/// </summary>
		/// <returns>unsigned</returns>
		unsigned getFreeSeats();

		/// <summary>
		/// ������� ������������ ������ Snack
		/// </summary>
		/// <param name="snack">Snacks::Snack</param>
		/// <returns>Snacks::Snack</returns>
		static Snacks::Snack* NewSnack(Snacks::Snack snack);
	};
}