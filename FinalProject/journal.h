#ifndef JOURNAL_H
#define JOURNAL_H

#include <vector>
#include <string>
#include "correspondence.h"

class Journal {
public:
    Journal(const std::string& journalType);

    void addCorrespondence(const Correspondence& item);
    void removeCorrespondence(int id);
    void displayJournal() const;
    void searchCorrespondence(const std::string& searchTerm) const;

    const std::vector<Correspondence>& getRecords() const;
    std::string getJournalType() const;

    // Метод для загрузки данных из вектора строк
    void loadFromStringVector(const std::vector<std::string>& lines);

private:
    std::string journalType;
    std::vector<Correspondence> records;
};

#endif // JOURNAL_H