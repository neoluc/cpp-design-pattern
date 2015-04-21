#include <iostream>

class Observer {
public:
	virtual void update(bool) = 0;
};

class Subject {
protected:
	std::vector<Observer*> observers;
public:
	virtual void register_observer(Observer*) = 0;
	virtual void remove_observer(Observer*) = 0;
	virtual void notify_observers() = 0;
};

class Human : public Subject {
public:
	virtual void register_observer(Observer *observer) {
		observers.push_back(observer);
	}
	virtual void remove_observer(Observer *observer) {
		std::vector<Observer*>::iterator it = std::find(observers.begin(), observers.end(), observer);
		if (it != observers.end()) {
			observers.erase(it);
		}	
	}
	virtual void notify_observers() {
		for (std::vector<Observer*>::iterator it = observers.begin(); it != observers.end(); it++) {
			(*it)->update(true);
		}
	}
};

class Dog : public Observer {
public:
	virtual void update() {
		cout << "yes" << endl;
	}
};

int main() {
	Dog d1;
	Dog d2;
	Dog d3;
	Dog d4;
	Dog d5;
	Human h;
	h.register_observer(&d1);
	h.register_observer(&d2);
	h.register_observer(&d3);
	h.register_observer(&d4);
	h.register_observer(&d5);
	h.notify_observers();
}