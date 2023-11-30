#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "./includes/encDec.h"

void encDec(const std::string &inputFile, const std::string &key){
	std::string ext = ".赤い目";
	std::string outputFile;
	std::string::size_type i = inputFile.find(ext);

	if (i != std::string::npos){
		outputFile = inputFile.substr(0, i);
	} else {
		outputFile = inputFile + ext;
	}

	std::ifstream inFile(inputFile);
	std::ofstream outFile(outputFile);

	if (!inFile.is_open()){
		std::cout << "input\n";
		std::cerr << "Erro ao abrir " << inputFile;
		exit(1);
	}

	if (!outFile.is_open()){
		std::cout << "output\n";
		std::cerr << "Erro ao abrir " << outputFile;
		exit(1);
	}

	char ch;
	size_t keyIndex = 0;

	while (inFile.get(ch)){
		// Operação XOR para encriptar/desencriptar
		ch = ch ^ key[keyIndex];
		++keyIndex;
		if (keyIndex >= key.length()){
			keyIndex = 0;
		}
		outFile.put(ch);
	}

	inFile.close();
	outFile.close();

	std::filesystem::remove(inputFile);
}

