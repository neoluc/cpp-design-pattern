#include <iostream>

class Animal {
public:
	virtual void run() = 0;
	virtual void add_leg() = 0;
};

class HKDog : public Animal {
public:
	virtual void run() {
		cout << "HK dog running" << endl;
	}
	virtual void add_leg() {
		cout << "added HK dog legs" << endl;
	}
};

class HKCat : public Animal {
public:
	virtual void run() {
		cout << "HK cat running" << endl;
	}
	virtual void add_leg() {
		cout << "added HK cat legs" << endl;
	}
};

class NYDog : public Animal {
public:
	virtual void run() {
		cout << "NY dog running" << endl;
	}
	virtual void add_leg() {
		cout << "added NY dog legs" << endl;
	}
};

class NYCat : public Animal {
public:
	virtual void run() {
		cout << "NY cat running" << endl;
	}
	virtual void add_leg() {
		cout << "added NY cat legs" << endl;
	}
};

class AnimalStore {
	virtual Animal *create_animal(std::string) = 0;
public:
	Animal *order_animal(std::string type) {
		Animal *animal = create_animal(type);
		animal->add_leg();
		return animal;
	}
};

class HKAnimalStore : public AnimalStore {
	Animal *create_animal(std::string type) {
		Animal *animal = nullptr;
		if (type == "cat") {
			animal = new HKCat();
		} else if (type == "dog") {
			animal = new HKDog();
		}
		return animal;
	}
};

class NYAnimalStore : public AnimalStore {
	Animal *create_animal(std::string type) {
		Animal *animal = nullptr;
		if (type == "cat") {
			animal = new NYCat();
		} else if (type == "dog") {
			animal = new NYDog();
		}
		return animal;
	}
};

int main() {
	HKAnimalStore hk_animal_store;
	NYAnimalStore ny_animal_store;
	AnimalStore *store_hk = &hk_animal_store;
	AnimalStore *store_ny = &ny_animal_store;
	Animal *cat = store_hk->order_animal("cat");
	Animal *dog = store_ny->order_animal("dog");
}