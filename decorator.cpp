#include <iostream>

class Drink {
public:
	virtual std::string get_description() = 0;
	virtual int get_cost() = 0;
};

class Water : public Drink {
public:
	virtual std::string get_description() {
		return "water";
	}
	virtual int get_cost() {
		return 10;
	}
};

class CondimentDecorator : public Drink{
public:
	virtual std::string get_description() = 0;
};

class Milk : public CondimentDecorator {
private:
	Drink *drink;
public:
	Milk(Drink *drink) {
		this->drink = drink;
	}
	virtual std::string get_description() {
		return drink->get_description() + " milk";
	}
	virtual int get_cost() {
		return drink->get_cost() + 2;
	}
};

int main() {
	Water water;
	Milk milk(&water);
	Drink *water_milk = &milk;
	cout << water_milk->get_description() << endl;
	cout << water_milk->get_cost() << endl;
}