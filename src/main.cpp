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

	Passenger *person;

	person = new Passenger;

	person->name = "john Doe";
	person->isPassennger = true;
	person->meal = VEGETERIAN;
	person->ID = 1008937867;
	
	if (person->isPassennger) {
		std::cout << "Hello, " << person->name << std::endl;
		std::cout << "ID: " << person->ID << std::endl;
		std::cout << "Meal Preference: " << person->meal << std::endl;
		return 0;
	}	
	std::cout << "NOT a passenger!" << std::endl;
	
	delete person;

	return -1;
}