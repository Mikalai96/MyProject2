#ifndef CORRESPONDENCE_H
#define CORRESPONDENCE_H

#include <string>

class Correspondence {
public:
    static int nextId;

    Correspondence(const std::string& date, const std::string& topic,
        const std::string& contact,
        const std::string& type = "incoming", int id = -1,
        const std::string& attachmentPath = "");

    // Геттеры
    int getId() const;
    std::string getDate() const;
    std::string getTopic() const;
    std::string getContact() const;
    std::string getType() const;
    std::string getAttachmentPath() const;

    // Сеттер для пути к прикрепленному файлу
    void setAttachmentPath(const std::string& path);

    // Преобразование в строку для отображения
    std::string toString() const;

    // Преобразование в CSV формат
    std::string toCSV() const;

    // Проверка на совпадение с поисковым запросом
    bool matchesSearch(const std::string& searchTerm) const;

private:
    int id;
    std::string date;
    std::string topic;
    std::string contact; // Отправитель или получатель
    std::string type; // "incoming" или "outgoing"
    std::string attachmentPath;
};

#endif // CORRESPONDENCE_H