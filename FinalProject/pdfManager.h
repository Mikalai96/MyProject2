#pragma once
#include <string>
#include <cstdlib>
#include <iostream>
#include <filesystem>
#include <sstream> 
#include <windows.h>
#include <objbase.h>
#include <commdlg.h> 

namespace fs = std::filesystem;

class PdfManager {
public:
    // Открытие PDF-файла с помощью системного приложения по умолчанию
    static bool openPdfFile(const std::string& filePath) {
        if (!fs::exists(filePath)) {
            std::cerr << "Файл не существует: " << filePath << std::endl;
            return false;
        }

#ifdef _WIN32
        std::string command = "start \"\" \"" + filePath + "\"";
#elif defined(__APPLE__)
        std::string command = "open \"" + filePath + "\"";
#else
        std::string command = "xdg-open \"" + filePath + "\"";
#endif

        int result = system(command.c_str());
        return (result == 0);
    }

    // Вызов сканера для создания PDF
    static std::string scanToPdf(const std::string& outputPath) {
        std::string filename = outputPath + "/scan_" + getCurrentTimestamp() + ".pdf";

#ifdef _WIN32
        // Использование WIA API для Windows
        try {
            // Инициализация COM
            CoInitialize(NULL);

            // Создание диалога выбора сканера
            std::string command = "rundll32.exe wiaaut.dll,SelectDeviceDlg";
            system(command.c_str());

            // Запуск приложения сканирования Windows
            command = "start ms-scan:";
            system(command.c_str());

            std::cout << "Запущено приложение сканирования Windows.\n";
            std::cout << "После завершения сканирования сохраните файл как: " << filename << std::endl;

            // Ждем, пока пользователь завершит сканирование
            std::cout << "Нажмите Enter после завершения сканирования...";
            std::cin.get();

            // Освобождение COM
            CoUninitialize();

            if (std::filesystem::exists(filename)) {
                return filename;
            }
            else {
                std::cout << "Файл не найден. Укажите путь к отсканированному файлу: ";
                std::string actualPath;
                std::getline(std::cin, actualPath);

                if (!actualPath.empty() && std::filesystem::exists(actualPath)) {
                    // Копируем файл в нужное место
                    std::filesystem::copy_file(actualPath, filename,
                        std::filesystem::copy_options::overwrite_existing);
                    return filename;
                }
            }
        }
        catch (...) {
            std::cerr << "Ошибка при работе со сканером" << std::endl;
        }
#else
        // Для Linux используем SANE
        std::string command = "xsane --save=" + filename;
        int result = system(command.c_str());
        if (result == 0 && std::filesystem::exists(filename)) {
            return filename;
        }
#endif

        return "";
    }

    // Добавлен static
    static std::string getFilePathFromDialog() {
        std::string filePath = "";
        char filename[MAX_PATH];
        OPENFILENAMEA ofn; // Используем ANSI версию
        ZeroMemory(&ofn, sizeof(ofn));
        ofn.lStructSize = sizeof(ofn);
        ofn.hwndOwner = NULL;
        ofn.lpstrFilter = "PDF Files (*.pdf)\0*.pdf\0All Files (*.*)\0*.*\0"; // Теперь это работает с ANSI
        ofn.lpstrFile = filename;
        ofn.lpstrFile[0] = '\0';
        ofn.nMaxFile = sizeof(filename);
        ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

        if (GetOpenFileNameA(&ofn)) { // Используем ANSI версию
            filePath = filename;
        }
        return filePath;
    }
private:
    // Получение текущей метки времени для уникальных имен файлов
    static std::string getCurrentTimestamp() {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);

        std::tm timeinfo;
#ifdef _WIN32
        localtime_s(&timeinfo, &time);
#else
        localtime_r(&time, &timeinfo);
#endif

        std::stringstream ss;
        ss << std::put_time(&timeinfo, "%Y%m%d_%H%M%S");
        return ss.str();
    }
};