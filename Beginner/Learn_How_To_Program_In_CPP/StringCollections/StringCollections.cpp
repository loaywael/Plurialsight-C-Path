#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int main(int argc, char **argv) {
	std::vector<std::string> vs = {"a", "e", "k", "b", "g", "c", "l"};
	std::vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (unsigned int i=0; i < vi.size(); i++){
		std::cout << vi[i] << " ";
	}

	std::cout << std::endl;
	std::sort(std::begin(vs), std::end(vs));
	for (auto i : vs){
		std::cout << i << " ";
	}
	std::cout << std::endl;

//	std::string SAVED_NAME = "Loay";
//	std::string name, msg;
//	std::cout << "enter your name: ";
//	std::cin >> name;
//	msg = "Hello, " + name;
//
//	if (name == SAVED_NAME){
//		msg += ", I know you!";
//	}
//	std::cout << msg << std::endl;
//	auto namePos = msg.find(' ') + 1;
//	if (msg.substr(namePos) == name){
//		std::cout << "Matched as expected!" << std::endl;
//	}
	return 0;
}
