#include <iostream>

class Screen {
public:
	void down() {
		cout << "screen down" << endl;
	}
};

class DvdPlayer {
public:
	void on() {
		cout << "dvd player on" << endl;
	}
};

class HomeTheaterFacade {
	Screen *screen;
	DvdPlayer *dvd_player;
public:
	HomeTheaterFacade(Screen *screen, DvdPlayer *dvd_player) {
		this->screen = screen;
		this->dvd_player = dvd_player;
	}
	void watch_movie() {
		screen->down();
		dvd_player->on();
	}
};

int main() {
	HomeTheaterFacade h(&Screen(), &DvdPlayer());
	h.watch_movie();
}