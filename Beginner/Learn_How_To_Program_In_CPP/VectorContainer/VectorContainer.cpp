#include <iostream>
#include <vector>
#include <algorithm>



int main(int argc, char **argv) {

	{
		using namespace std;
		cout << "hello from scope" << endl;
	}
	std::vector<std::string> vs = {"a", "e", "k", "b", "g", "c", "l", "k"};
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
	int nKs = std::count(std::begin(vs), std::end(vs), "k");
	std::cout << "number of Ks in Vs is: " << nKs << std::endl;
	return 0;
}
