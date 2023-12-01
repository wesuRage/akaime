#include <iostream>
#include <vector>
#include <filesystem>
#include "./includes/fileFinder.h"

namespace fs = std::filesystem;

std::vector<std::string> fileFinder(const std::string& startDir) {
    std::vector<std::string> Files;

    try {
        for (const auto& entry : fs::recursive_directory_iterator(startDir)) {
            if (entry.is_regular_file()) {
                Files.push_back(entry.path().string());
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return Files;
}

