#include <iostream>
#include <dirent.h>
#include <vector>
#include "./includes/fileFinder.h"

std::vector<std::string> fileFinder(std::string startDir) {
	DIR* dir = opendir(startDir.c_str());

	if (!dir) {
	std::cerr << "Erro ao abrir o diretório." << std::endl;
		exit(1);
	}

	struct dirent* entry;
	std::vector<std::string> Files;

	while ((entry = readdir(dir)) != nullptr) {
		if (entry->d_type == DT_REG) {    
			std::string result = startDir + "/" + entry->d_name;
			Files.push_back(result);
		} else if (entry->d_type == DT_DIR && std::string(entry->d_name) != "." && std::string(entry->d_name) != "..") {
			std::string result = startDir + "/" + entry->d_name;
			std::vector<std::string> subFiles = fileFinder(result);
			Files.insert(Files.end(), subFiles.begin(), subFiles.end());
		}
	}
	
	closedir(dir);
	return Files;
}

