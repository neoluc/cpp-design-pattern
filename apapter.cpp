#include <iostream>

class Bird {
public:
	virtual void fly() = 0;
};

class Parrot : public Bird {
public:
	virtual void fly() {
		cout << "parrot fly" << endl;
	}
};

class Fish {
public:
	virtual void swim() = 0;
};

class Shark : public Fish {
public:
	virtual void swim() {
		cout << "shark swim" << endl;
	}
};

class FishAdapter : public Bird {
	Fish *fish;
public:
	FishAdapter(Fish *fish) {
		this->fish = fish;
	}
	virtual void fly() {
		fish->swim();
	}
};

int main() {
	Shark shark;
	FishAdapter fish_adapter(&Shark());
	Bird *bird_shake = &fish_adapter;
	bird_shake->fly();
}