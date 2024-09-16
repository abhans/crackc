#include <iostream>
#include <string>

enum MealType {
	DEFAULT,
	VEGETERIAN,
	VEGAN,
	LOW_FAT
};

struct Passenger
{
	std::string name;
	bool isPassennger;
	MealType meal;
	long ID;

};

int main() {

	Passenger person = {
		"John Doe",
		true,
		DEFAULT,
		1334988008
	};
	
	if (person.isPassennger) {
		std::cout << "Hello, " << person.name << std::endl;
		std::cout << "ID: " << person.ID << std::endl;
		std::cout << "Meal Preference: " << person.meal << std::endl;
		return 0;
	}	
	std::cout << "NOT a passenger!" << std::endl;
	return -1;
}