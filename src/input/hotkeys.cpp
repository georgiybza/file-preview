// TODO: Hotkey Implementation: Left Arrow = Left, Right Arrow = Right, Space = Open/Close (depend. on state)
#include <conio.h>
#include <iostream>
#define UP_KEY 72
#define DOWN_KEY 80
#define LEFT_KEY 75
#define RIGHT_KEY 77 

// TODO: Implement Proper Functionality (DO x when y PRESSED) (ONLY WHEN ACTIVE STATE)
int get_user_input(int pressed_key) {
	switch(pressed_key) {
		case UP_KEY:
			std::cout << "UP KEY PRESSED" << std::endl;
		case DOWN_KEY:
			std::cout << "DOWN KEY PRESSED" << std::endl;
		case LEFT_KEY:
			std::cout << "LEFT KEY PRESSED" << std::endl;
		case RIGHT_KEY:
			std::cout << "RIGHT KEY PRESSED" << std::endl;
	}
}


// TODO: implement key checking for different OS's; for now Linux is main priority
// TODO: QT Event System Captures All Keystrokes on Focused Window; in other words this might be what I need
int main() {

	

}