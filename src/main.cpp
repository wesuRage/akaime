#include "./includes/fileFinder.h"
#include "./includes/encDec.h"
#include <iostream>


int main(){
	std::string input;
	std::string key;

	std::cout << "Enter the main directory: ";
	std::getline(std::cin, input);
	std::cout << "Enter the key: ";
	std::getline(std::cin, key);

	std::vector<std::string> files = fileFinder(input);

	for (int i = 0; i < files.size(); i++){
		std::cout << files[i] << '\n';
		encDec(files[i], key);
	}

	return 0;
}
