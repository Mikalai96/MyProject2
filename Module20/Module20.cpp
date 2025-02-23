#include <iostream>
#include <filesystem>
#include <string>


size_t fileCount = 0;
size_t folderCount = 0;

int main() {
    std::cout << "Enter the path to folder: ";
    std::string userInput;
    std::getline(std::cin, userInput); 

    std::filesystem::path path = userInput;
    if (std::filesystem::exists(path)) {
        std::cout << "Folder exist" << std::endl;
    }
    for (const auto& item : std::filesystem::directory_iterator(userInput)) {
        if (item.is_regular_file()) {
            ++fileCount;
            if (item.path().extension() == ".exe") {
                std::cout << " - " << item.path().filename().string() << std::endl;
            }
        }
        else if (item.is_directory()) {
            ++folderCount;
        }
    }
    std::cout << "Files: " << fileCount << std::endl;
    std::cout << "Folders: " << folderCount << std::endl;
    return 0;
}