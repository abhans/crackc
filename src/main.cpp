#include <iostream>

// Mixin: Printable
class Printable {
public:
    void print() const {
        std::cout << "Printed..." << std::endl;
        return;
    }
};

// Mixin: Savable
class Savable {
public:
    void save() const {
        std::cout << "Saved..." << std::endl;
        return;
    }
};

// Class: Document
//   + Printable (Mixin)
//   + Saveble (Mixin)
class Document : public Printable, public Savable {
public:
    // Document-specific methods here
};

int main() {
    Document doc;
    doc.print();  // From Printable mixin
    doc.save();   // From Savable mixin
    
	return 0;
}