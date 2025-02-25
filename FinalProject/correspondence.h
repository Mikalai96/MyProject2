#ifndef CORRESPONDENCE_H
#define CORRESPONDENCE_H

#include <string>
#include <sstream>


class Correspondence {
public:
    inline static int nextId = 0;

    Correspondence(const std::string& date, const std::string& topic,
        const std::string& contact,
        const std::string& type = "incoming", int id = -1,
        const std::string& attachmentPath = "")
        : date(date), topic(topic), contact(contact),
        type(type), id(id), attachmentPath(attachmentPath) {
        // Если ID не указан, генерируем новый
        if (id == -1) {
            this->id = ++nextId; // Используем глобальную переменную
        }
        else if (id > nextId) {
            nextId = id; // Обновляем nextId, если загружен больший ID
        }
    }

    // Геттеры
    int getId() const { return id; }
    std::string getDate() const { return date; }
    std::string getTopic() const { return topic; }
    std::string getContact() const { return contact; }
    std::string getType() const { return type; }
    std::string getAttachmentPath() const { return attachmentPath; }

    // Сеттер для пути к прикрепленному файлу
    void setAttachmentPath(const std::string& path) { attachmentPath = path; }

    // Преобразование в строку для отображения
    std::string toString() const {
        std::stringstream ss;
        ss << "№" << id << " от " << date << " | ";
        if (type == "incoming") {
            ss << "От: " << contact;
        }
        else {
            ss << "Кому: " << contact;
        }
        ss << " | Тема: " << topic;

        // Добавляем информацию о наличии прикрепленного файла
        if (!attachmentPath.empty()) {
            ss << " | PDF: Прикреплен";
        }
        else {
            ss << " | PDF: Отсутствует";
        }

        return ss.str();
    }

    // Преобразование в CSV формат
    std::string toCSV() const {
        std::stringstream ss;
        ss << id << "," << date << "," << contact << ","
            << "\"" << topic << "\"";
        return ss.str();
    }

    // Проверка на совпадение с поисковым запросом
    bool matchesSearch(const std::string& searchTerm) const {
        std::string lowerSearchTerm = searchTerm;
        std::string lowerTopic = topic;
        std::string lowerContact = contact;

        // Преобразование к нижнему регистру для поиска без учета регистра
        for (auto& c : lowerSearchTerm) c = std::tolower(c);
        for (auto& c : lowerTopic) c = std::tolower(c);
        for (auto& c : lowerContact) c = std::tolower(c);

        return lowerTopic.find(lowerSearchTerm) != std::string::npos ||
            lowerContact.find(lowerSearchTerm) != std::string::npos ||
            std::to_string(id).find(searchTerm) != std::string::npos;
    }
   
private:
    int id;
    std::string date;
    std::string topic;
    std::string contact; // Отправитель или получатель
    std::string type; // "incoming" или "outgoing"
    std::string attachmentPath;
   
};

#endif // CORRESPONDENCE_H
