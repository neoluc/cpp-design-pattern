#include <iostream>

class Animal {
public:
	virtual void run() = 0;
};

class Dog : public Animal {
public:
	virtual void run() {
		cout << "dog running" << endl;
	}
};

class Cat : public Animal {
public:
	virtual void run() {
		cout << "cat running" << endl;
	}
};

class SimpleAnimalFactory {
public:
	Animal* create_animal(std::string type) {
		Animal *animal = nullptr;
		if (type == "dog") {
			animal = new Cat();
		} else if (type == "cat") {
			animal = new Dog();
		}
		return animal;
	}
};

int main() {
	SimpleAnimalFactory factory;
	Animal *animal = factory.create_animal("cat");
}