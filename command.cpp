#include <iostream>

class Command {
public:
	virtual void execute() = 0;
};

class Fan {
public:
	void on() {
		cout << "on fan" << endl;
	}
	void off() {
		cout << "off fan" << endl;
	}
};

class FanOnCommand : public Command {
	Fan *fan;
public:
	FanOnCommand(Fan *fan) {
		this->fan = fan;
	}
	virtual void execute() {
		fan->on();
	}
};

class FanOffCommand : public Command {
	Fan *fan;
public:
	FanOffCommand(Fan *fan) {
		this->fan = fan;
	}
	virtual void execute() {
		fan->off();
	}
};

class Light {
public:
	void on() {
		cout << "on light" << endl;
	}
	void off() {
		cout << "off light" << endl;
	}
};

class LightOnCommand : public Command {
	Light *light;
public:
	LightOnCommand(Light *light) {
		this->light = light;
	}
	virtual void execute() {
		light->on();
	}
};

class LightOffCommand : public Command {
	Light *light;
public:
	LightOffCommand(Light *light) {
		this->light = light;
	}
	virtual void execute() {
		light->off();
	}
};

class RemoteControl {
	Command *on_commands[7];
	Command *off_commands[7];
public:
	RemoteControl() {
		for (int i = 0; i <  7; i++) {
			on_commands[i] = nullptr;
			off_commands[i] = nullptr;
		}
	}
	void set_command(int slot, Command *on_command, Command *off_command) {
		on_commands[slot] = on_command;
		off_commands[slot] = off_command;
	}
	void press_button_on(int slot) {
		on_commands[slot]->execute();
	}
	void press_button_off(int slot) {
		off_commands[slot]->execute();
	}
};

int main() {
	RemoteControl remote;
	Light light;
	LightOnCommand light_on(&light);
	LightOffCommand light_off(&light);
	Fan fan;
	FanOnCommand fan_on(&fan);
	FanOffCommand fan_off(&fan);
	remote.set_command(0, &light_on, &light_off);
	remote.set_command(1, &fan_on, &fan_off);
	remote.press_button_on(0);
	remote.press_button_off(1);
}