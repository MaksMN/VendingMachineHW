#pragma once
#include "Misc.h"
#include "Snack.h"

namespace Snacks {

	Snack::Snack(std::string name, unsigned price, unsigned calories)
	{
		setPrice(price);
		setCalories(calories);
		Name = name;
		Misc::SendDebugMsg("Конструктор Snack");
	}

	Snack::Snack()
	{
		Misc::SendDebugMsg("Конструктор по умолчанию Snack");
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
		Price = Misc::GetUnsignedNonZeroNum(price, "Цена снека должна быть положительным числом больше нуля.\nВведите число : ");
	}

	unsigned Snack::getCalories()
	{
		return Calories;
	}

	void Snack::setCalories(unsigned calories)
	{
		Calories = Misc::GetUnsignedNonZeroNum(calories, "Калорийность продукта должна быть положительным числом больше нуля.\nВведите число : ");
	}
}