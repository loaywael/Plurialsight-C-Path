#include <iostream>
#include <string>


int main(int argc, char **argv) {

	std::string SAVED_NAME = "Loay";
	std::string name, msg;
	std::cout << "enter your name: ";
	std::cin >> name;
	msg = "Hello, " + name;

	if (name == SAVED_NAME){
		msg += ", I know you!";
	}
	std::cout << msg << std::endl;
	auto namePos = msg.find(' ') + 1;
	if (msg.substr(namePos) == name){
		std::cout << "Matched as expected!" << std::endl;
	}
	return 0;
}
