#include "pdfManager.h"
#include <cstdlib>
#include <iostream>
#include <filesystem>
#include <sstream> 
#include <chrono>
#include <iomanip>

#ifdef _WIN32
#include <windows.h>
#include <objbase.h>
#include <commdlg.h> 
#endif

namespace fs = std::filesystem;

bool PdfManager::openPdfFile(const std::string& filePath) {
    if (!fs::exists(filePath)) {
        std::cerr << "Файл не существует: " << filePath << std::endl;
        return false;
    }
    std::string command = "start \"\" \"" + filePath + "\"";
    int result = system(command.c_str());
    return (result == 0);
}

//std::string PdfManager::scanToPdf(const std::string& outputPath) {
//    std::string filename = outputPath + "/scan_" + getCurrentTimestamp() + ".pdf";    
//    try {
//        // Инициализация COM
//        CoInitialize(NULL);
//
//        // Создание диалога выбора сканера
//        std::string command = "rundll32.exe wiaaut.dll,SelectDeviceDlg";
//        system(command.c_str());
//
//        // Запуск приложения сканирования Windows
//        command = "start ms-scan:";
//        system(command.c_str());
//
//        std::cout << "Запущено приложение сканирования Windows.\n";
//        std::cout << "После завершения сканирования сохраните файл как: " << filename << std::endl;
//
//        // Ждем, пока пользователь завершит сканирование
//        std::cout << "Нажмите Enter после завершения сканирования...";
//        std::cin.get();
//
//        // Освобождение COM
//        CoUninitialize();
//
//        if (std::filesystem::exists(filename)) {
//            return filename;
//        }
//        else {
//            std::cout << "Файл не найден. Укажите путь к отсканированному файлу: ";
//            std::string actualPath;
//            std::getline(std::cin, actualPath);
//
//            if (!actualPath.empty() && std::filesystem::exists(actualPath)) {
//                // Копируем файл в нужное место
//                std::filesystem::copy_file(actualPath, filename,
//                    std::filesystem::copy_options::overwrite_existing);
//                return filename;
//            }
//        }
//    }
//    catch (...) {
//        std::cerr << "Ошибка при работе со сканером" << std::endl;
//    }
//    return "";
//}

std::string PdfManager::getFilePathFromDialog() {
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

    if (GetOpenFileNameA(&ofn)) { 
    }
    return filePath;
}

std::string PdfManager::getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    std::tm timeinfo; 
    localtime_s(&timeinfo, &time);
    std::stringstream ss;
    ss << std::put_time(&timeinfo, "%Y%m%d_%H%M%S");
    return ss.str();
}