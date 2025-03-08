#include "correspondence.h"
#include <sstream>
#include <algorithm>
#include <cctype>

int Correspondence::nextId = 0;

Correspondence::Correspondence(const std::string& date, const std::string& topic,
    const std::string& contact,
    const std::string& type, int id,
    const std::string& attachmentPath)
    : date(date), topic(topic), contact(contact),
    type(type), id(id), attachmentPath(attachmentPath) {
    // Если ID не указан, генерируем новый
    if (id == -1) {
        this->id = ++nextId; // Используем статическую переменную класса
    }
    else if (id > nextId) {
        nextId = id; // Обновляем nextId, если загружен больший ID
    }
}

int Correspondence::getId() const {
    return id;
}

std::string Correspondence::getDate() const {
    return date;
}

std::string Correspondence::getTopic() const {
    return topic;
}

std::string Correspondence::getContact() const {
    return contact;
}

std::string Correspondence::getType() const {
    return type;
}

std::string Correspondence::getAttachmentPath() const {
    return attachmentPath;
}

void Correspondence::setAttachmentPath(const std::string& path) {
    attachmentPath = path;
}

std::string Correspondence::toString() const {
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

std::string Correspondence::toCSV() const {
    std::stringstream ss;
    ss << id << "," << date << "," << contact << ","
        << "\"" << topic << "\"";
    return ss.str();
}

bool Correspondence::matchesSearch(const std::string& searchTerm) const {
    std::string lowerSearchTerm = searchTerm;
    std::string lowerTopic = topic;
    std::string lowerContact = contact;

    // Преобразование к нижнему регистру для поиска без учета регистра
    std::transform(lowerSearchTerm.begin(), lowerSearchTerm.end(), lowerSearchTerm.begin(),
        [](unsigned char c) { return std::tolower(c); });
    std::transform(lowerTopic.begin(), lowerTopic.end(), lowerTopic.begin(),
        [](unsigned char c) { return std::tolower(c); });
    std::transform(lowerContact.begin(), lowerContact.end(), lowerContact.begin(),
        [](unsigned char c) { return std::tolower(c); });

    return lowerTopic.find(lowerSearchTerm) != std::string::npos ||
        lowerContact.find(lowerSearchTerm) != std::string::npos ||
        std::to_string(id).find(searchTerm) != std::string::npos;
}