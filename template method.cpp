#include <iostream>

class Animal {
public:
	void prepare_animal() {
		add_legs();
		add_heads();
	}
	virtual void add_legs() = 0;
	virtual void add_heads() = 0;
};

class Dog : public Animal {
public:
	void add_legs() {
		cout << "dog add 4 legs" << endl;
	}
	void add_heads() {
		cout << "dog add 1 head" << endl;
	}
};

int main() {
	Animal *animal = &Dog();
	animal->prepare_animal();
}