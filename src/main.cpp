#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

/* OpenCV Version */
const std::string OPENCV_VERSION = cv::getVersionString();

// Usage of "this" for Classes
class Person {
    private:
        int age;
        std::string name;

    public:
        // Default Constructor
        Person() : age(0), name("") {}

        // Parametesrized Constructor
        Person(int _age, std::string _name) : age(_age), name(_name) {}

        std::string getName() {
            return this->name;
        };
        int getAge() {
            return this->age;
        };
        
        Person& setAge(int age) {
            this->age = age;
            return *this;
        };

        Person& setName(std::string name) {
            this->name = name;
            return *this;
        };
};

int main() {
    std::cout << "OpenCV: " << OPENCV_VERSION << std::endl;
    Person personMe;
    personMe.setAge(25);
    personMe.setName("Bilgehan");
    
    std::cout << "Name: " << personMe.getName() << std::endl;
    std::cout << "Age: " << personMe.getAge() << std::endl;
}  