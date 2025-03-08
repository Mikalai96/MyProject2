#ifndef PDF_MANAGER_H
#define PDF_MANAGER_H

#include <string>

class PdfManager {
public:
    // Открытие PDF-файла с помощью системного приложения по умолчанию
    static bool openPdfFile(const std::string& filePath);

    // Вызов сканера для создания PDF
    static std::string scanToPdf(const std::string& outputPath);

    // Получение пути к файлу через диалог выбора файла
    static std::string getFilePathFromDialog();

private:
    // Получение текущей метки времени для уникальных имен файлов
    static std::string getCurrentTimestamp();
};

#endif // PDF_MANAGER_H