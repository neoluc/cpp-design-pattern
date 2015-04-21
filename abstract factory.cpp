#include <iostream>

class Leg {
	std::string type;
public:
	Leg(std::string type) {
		this->type = type;
	}
};

class Wing {
	std::string type;
public:
	Wing(std::string type) {
		this->type = type;
	}
};

class BodyFactory {
public:
	virtual Leg *create_leg() = 0;
	virtual Wing *create_wing() = 0;
};


class HKBodyFactory : public BodyFactory {
public:
	virtual Leg *create_leg() {
		return new Leg("HK leg");
	}
	virtual Wing *create_wing() {
		return new Wing("HK wing");
	}
};

class Animal {
protected:
	BodyFactory *factory;
	Leg *leg;
	Wing *wing;
public:
	Animal(BodyFactory *factory) {
		this->factory = factory;
		leg = nullptr;
		wing = nullptr;
	}
	virtual void prepare() = 0;
};

class Dog : public Animal {
public:
	Dog(BodyFactory *factory) : Animal(factory) {}
	~Dog() {
		delete leg;
	}
	virtual void prepare() {
		leg = factory->create_leg();
	}
};

class Bird : public Animal {
public:
	Bird(BodyFactory *factory) : Animal(factory) {}
	~Bird() {
		delete wing;
	}
	virtual void prepare() {
		wing = factory->create_wing();
	}
};

class AnimalStore {
public:
	virtual Animal *create_animal(std::string) = 0;
};

class HKAnimalStore : public AnimalStore{
public:
	Animal *create_animal(std::string type) {
		Animal *animal = nullptr;
		HKBodyFactory hk_body_factory;
		BodyFactory *factory = &hk_body_factory;
		if (type == "dog") {
			animal = new Dog(factory);
		} else if (type == "bird") {
			animal = new Bird(factory);
		}
		return animal;
	}
};

int main() {
	HKAnimalStore store_hk;
	AnimalStore *store = &store_hk;
	Animal *dog = store->create_animal("dog");
}