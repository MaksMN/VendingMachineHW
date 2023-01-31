#pragma once
#include <iostream>
#include <string>
namespace Snacks {
	enum Statuses {
		null = 0,
		sale = 1,
		sold = 2,
		eaten = 4,
		inSnackSlot = 16
	};

	class Snack
	{
	public:
		std::string	Name = ""; // название
		Statuses statuses = Statuses::null;

		Snack(std::string name, unsigned price, unsigned calories);
		Snack();
		~Snack();

		unsigned getPrice();
		void setPrice(unsigned price);

		unsigned getCalories();
		void setCalories(unsigned calories);

	private:
		unsigned Price = 0; // Цена
		unsigned Calories = 0; // Калорийность
	};
}