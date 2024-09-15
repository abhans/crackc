#include <iostream>

int main() {
	
	int X[] = {1, 0, 0, 1, 0, 0, 1};

	int age = 23;
	int *ageP = &age;
	
	/* &age = ageP */
	/* age = *ageP */

	// std::cout << age << std::endl;
	// std::cout << &age << std::endl;

	// std::cout << *ageP << std::endl;
	// std::cout << ageP << std::endl;
	
	std::cout << &X[0] << std::endl;
	std::cout << &X[1] << std::endl;
	std::cout << &X[2] << std::endl;
	std::cout << &X[3] << std::endl;
	
	return 0;
}