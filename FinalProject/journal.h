#ifndef JOURNAL_H
#define JOURNAL_H

#include <vector>
#include <string>
#include <iostream>
#include "correspondence.h"

class Journal {
public:
    Journal(const std::string& journalType) : journalType(journalType) {}

    void addCorrespondence(const Correspondence& item) {
        records.push_back(item);
    }

    void removeCorrespondence(int id) {
        for (auto it = records.begin(); it != records.end(); ++it) {
            if (it->getId() == id) {
                records.erase(it);
                return;
            }
        }
    }

    void displayJournal() const {
        if (records.empty()) {
            std::cout << "Журнал пуст.\n";
            return;
        }

        for (const auto& record : records) {
            std::cout << record.toString() << std::endl;
        }
    }

    void searchCorrespondence(const std::string& searchTerm) const {
        bool found = false;

        for (const auto& record : records) {
            if (record.matchesSearch(searchTerm)) {
                std::cout << record.toString() << std::endl;
                found = true;
            }
        }

        if (!found) {
            std::cout << "Документы не найдены.\n";
        }
    }

    const std::vector<Correspondence>& getRecords() const {
        return records;
    }

    std::string getJournalType() const {
        return journalType;
    }

    // Метод для загрузки данных из вектора строк
    
    void loadFromStringVector(const std::vector<std::string>& lines) {
        records.clear();

        for (const auto& line : lines) {
            std::stringstream ss(line);
            std::string idStr, date, contact, topic, attachmentPath;

            std::getline(ss, idStr, ',');
            std::getline(ss, date, ',');
            std::getline(ss, contact, ',');

            // Обработка темы, которая может содержать запятые в кавычках
            char c;
            ss >> c; // Считываем открывающую кавычку
            std::getline(ss, topic, '"');
            ss >> c; // Считываем запятую после закрывающей кавычки

            // Обработка пути к прикрепленному файлу
            ss >> c; // Считываем открывающую кавычку
            std::getline(ss, attachmentPath, '"');

            int id = std::stoi(idStr);
            records.push_back(Correspondence(date, topic, contact, journalType, id, attachmentPath));
        }
    }

private:
    std::string journalType; // Добавьте это объявление    
    std::vector<Correspondence> records;
};

#endif // JOURNAL_H