#include "file_manager.h"
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

namespace fs = std::filesystem;

FileManager::FileManager() {
    // Путь по умолчанию - текущая директория
    storagePath = std::filesystem::current_path().string() + "/correspondence_data";

    // Создаем структуру директорий
    createDirectoryStructure();
}

void FileManager::setStoragePath(const std::string& userPath) {
    if (std::filesystem::exists(userPath)) {
        storagePath = userPath;
    }
    else {
        // Попытка создать директорию
        if (std::filesystem::create_directories(userPath)) {
            storagePath = userPath;
        }
        else {
            throw std::runtime_error("Невозможно создать указанную директорию");
        }
    }

    // Создаем структуру директорий в новом месте хранения
    createDirectoryStructure();
}

std::string FileManager::getStoragePath() const {
    return storagePath;
}

void FileManager::createDirectoryStructure() {
    // Создаем основную директорию, если она не существует
    if (!std::filesystem::exists(storagePath)) {
        std::filesystem::create_directories(storagePath);
    }

    // Создаем директорию для входящих документов
    std::string incomingDir = storagePath + "/incoming_attachments";
    if (!std::filesystem::exists(incomingDir)) {
        std::filesystem::create_directories(incomingDir);
    }

    // Создаем директорию для исходящих документов
    std::string outgoingDir = storagePath + "/outgoing_attachments";
    if (!std::filesystem::exists(outgoingDir)) {
        std::filesystem::create_directories(outgoingDir);
    }
}

void FileManager::loadJournal(Journal& journal) {
    std::string journalPath = storagePath + "/" + journal.getJournalType() + "_journal.csv";

    if (!fs::exists(journalPath)) {
        return; // Файл не существует, нечего загружать
    }

    std::ifstream file(journalPath);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл журнала: " + journalPath);
    }

    std::vector<std::string> lines;
    std::string line;

    // Пропускаем заголовок
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }

    file.close();
    journal.loadFromStringVector(lines);
}

void FileManager::saveJournal(const Journal& journal) {
    std::string journalPath = storagePath + "/" + journal.getJournalType() + "_journal.csv";

    std::ofstream file(journalPath);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для записи: " + journalPath);
    }

    // Записываем заголовок
    file << "id,date,contact,topic,attachmentPath\n";

    // Записываем данные
    for (const auto& record : journal.getRecords()) {
        file << record.getId() << ","
            << record.getDate() << ","
            << record.getContact() << ","
            << "\"" << record.getTopic() << "\"" << ","
            << "\"" << record.getAttachmentPath() << "\""
            << "\n";
    }

    file.close();
}

void FileManager::exportJournalToTXT(const Journal& journal, const std::string& filename) {
    std::string exportPath = storagePath + "/" + filename;
    if (exportPath.find(".txt") == std::string::npos) {
        exportPath += ".txt";
    }

    std::ofstream file(exportPath);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось создать файл для экспорта: " + exportPath);
    }

    // Записываем заголовок
    file << "=== Журнал ";
    if (journal.getJournalType() == "incoming") {
        file << "входящей";
    }
    else {
        file << "исходящей";
    }
    file << " корреспонденции ===\n\n";

    // Записываем данные
    for (const auto& record : journal.getRecords()) {
        file << "№" << record.getId() << " от " << record.getDate() << " | ";
        if (journal.getJournalType() == "incoming") {
            file << "От: " << record.getContact();
        }
        else {
            file << "Кому: " << record.getContact();
        }
        file << " | Тема: " << record.getTopic() << "\n";
    }

    file.close();
    std::cout << "Журнал успешно экспортирован в " << exportPath << std::endl;
}

std::string FileManager::copyFileToStorage(const std::string& sourcePath, const std::string& documentType) {
    if (!std::filesystem::exists(sourcePath)) {
        throw std::runtime_error("Исходный файл не существует: " + sourcePath);
    }

    // Определяем директорию в зависимости от типа документа
    std::string attachmentsDir;
    if (documentType == "incoming") {
        attachmentsDir = storagePath + "/incoming_attachments";
    }
    else {
        attachmentsDir = storagePath + "/outgoing_attachments";
    }

    // Создаем директорию, если она не существует
    if (!std::filesystem::exists(attachmentsDir)) {
        std::filesystem::create_directories(attachmentsDir);
    }

    // Получаем имя файла из пути
    std::string filename = std::filesystem::path(sourcePath).filename().string();

    // Добавляем временную метку к имени файла для уникальности
    std::string timestamp = getCurrentTimestamp();
    std::string newFilename = timestamp + "_" + filename;

    std::string destPath = attachmentsDir + "/" + newFilename;

    try {
        std::filesystem::copy_file(sourcePath, destPath, std::filesystem::copy_options::overwrite_existing);
        return destPath;
    }
    catch (const std::filesystem::filesystem_error& e) {
        throw std::runtime_error("Ошибка при копировании файла: " + std::string(e.what()));
    }
}

std::string FileManager::getCurrentTimestamp() {
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

void FileManager::saveLastId(int lastId) {
    std::string idFilePath = storagePath + "/last_id.txt";
    std::ofstream file(idFilePath);
    if (file.is_open()) {
        file << lastId;
        file.close();
    }
}

int FileManager::loadLastId() {
    std::string idFilePath = storagePath + "/last_id.txt";
    if (!std::filesystem::exists(idFilePath)) {
        return 0; // Если файл не существует, начинаем с 0
    }

    std::ifstream file(idFilePath);
    int lastId = 0;
    if (file.is_open()) {
        file >> lastId;
        file.close();
    }
    return lastId;
}