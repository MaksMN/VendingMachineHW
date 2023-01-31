#pragma once
#include "Misc.h"
#include "Snack.h"

namespace Snacks {

	Snack::Snack(std::string name, unsigned price, unsigned calories)
	{
		setPrice(price);
		setCalories(calories);
		Name = name;
		Misc::SendDebugMsg("����������� Snack");
	}

	Snack::Snack()
	{
		Misc::SendDebugMsg("����������� �� ��������� Snack");
	}

	Snack::~Snack()
	{
		Misc::SendDebugMsg("Destructor Snack");
	}

	unsigned Snack::getPrice()
	{
		return Price;
	}

	void Snack::setPrice(unsigned price)
	{
		Price = Misc::GetUnsignedNonZeroNum(price, "���� ����� ������ ���� ������������� ������ ������ ����.\n������� ����� : ");
	}

	unsigned Snack::getCalories()
	{
		return Calories;
	}

	void Snack::setCalories(unsigned calories)
	{
		Calories = Misc::GetUnsignedNonZeroNum(calories, "������������ �������� ������ ���� ������������� ������ ������ ����.\n������� ����� : ");
	}
}