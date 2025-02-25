#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include <string>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

class ConfigManager {
public:
    ConfigManager(const std::string& configFile = "config.ini") : configFilePath(configFile) {}

    void saveStoragePath(const std::string& path) {
        std::ofstream configFile(configFilePath);
        if (configFile.is_open()) {
            configFile << "storage_path=" << path << std::endl;
            configFile.close();
        }
    }

    std::string loadStoragePath() {
        std::string path = "";
        std::ifstream configFile(configFilePath);
        if (configFile.is_open()) {
            std::string line;
            while (std::getline(configFile, line)) {
                if (line.find("storage_path=") == 0) {
                    path = line.substr(13); // Длина "storage_path="
                    break;
                }
            }
            configFile.close();
        }
        return path;
    }

private:
    std::string configFilePath;
};

#endif // CONFIG_MANAGER_H