#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <vector>
#include "journal.h"

class FileManager {
public:
    FileManager();

    // Метод для установки пользовательского пути хранения
    void setStoragePath(const std::string& userPath);

    // Получение текущего пути хранения
    std::string getStoragePath() const;

    // Создание структуры директорий для хранения файлов
    void createDirectoryStructure();

    // Загрузка журнала из файла
    void loadJournal(Journal& journal);

    // Сохранение журнала в файл
    void saveJournal(const Journal& journal);

    // Экспорт журнала в TXT-файл
    void exportJournalToTXT(const Journal& journal, const std::string& filename);

    // Копирование файла в хранилище с учетом типа документа
    std::string copyFileToStorage(const std::string& sourcePath, const std::string& documentType);

    // Получение текущей метки времени
    std::string getCurrentTimestamp();

    // Сохранение последнего использованного ID
    void saveLastId(int lastId);

    // Загрузка последнего использованного ID
    int loadLastId();

private:
    std::string storagePath;
};

#endif // FILE_MANAGER_H