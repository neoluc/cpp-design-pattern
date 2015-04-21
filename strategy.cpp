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
		fly_behaviour = new FlyWithWings();
	}
	~NormalDuck() {
		delete fly_behaviour;
	}
	virtual void display() {
		cout << "i am a normal duck" << endl;
	}
};

int main() {
	NormalDuck normal_duck;
	Duck *d = &normal_duck;
	d.perform_fly();
}