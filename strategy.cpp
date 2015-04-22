#include <iostream>

class FlyBehaviour {
public:
	virtual void fly() = 0;
};

class FlyWithWings : public FlyBehaviour {
public:
	virtual void fly() {
		cout << "fly with wings" << endl;
	}
};

class Duck {
public:
	FlyBehaviour *fly_behaviour;
	void perform_fly() {
		fly_behaviour->fly();
	}
	virtual void display() = 0;
};

class NormalDuck : public Duck {
public:
	NormalDuck() {
		fly_behaviour = &FlyWithWings();
	}
	virtual void display() {
		cout << "i am a normal duck" << endl;
	}
};

int main() {
	Duck *d = &NormalDuck();
	d.perform_fly();
}