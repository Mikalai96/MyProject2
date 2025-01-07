#include "ClassBook.h"

class Book
{
public:
	// Конструктор по умолчанию
	Book() : title("Unknown"), author("Unknown"), year(0), ISBN(nullptr) {}

	// Конструктор с параметрами
	Book(const std::string& bTitle, const std::string& bAuthor, int bYear, const char* bISBN) : title(bTitle), author(bAuthor), year(bYear) {
		ISBN = new char[strlen(bISBN) + 1];
		strcpy_s(ISBN, strlen(bISBN) + 1, bISBN);
	}

	// Конструктор копирования
	Book(const Book& other) : title(other.title), author(other.author), year(other.year) {
		if (other.ISBN) {
			ISBN = new char[strlen(other.ISBN) + 1];
			strcpy_s(ISBN, strlen(other.ISBN) + 1, other.ISBN);
		}
		else {
			ISBN = nullptr;
		}
	}
	// Геттеры 
	std::string getTitle() const {
		return title;
	}
	std::string getAuthor() const {
		return author;
	}
	int getYear() const {
		return year;
	}
	const char* getISBN() const {
		return ISBN;
	}
	// Метод вывода инфо о книге
	void printInfo() const {
		std::cout << "Title: " << title << "\n"
			<< "Author: " << author << "\n"
			<< "Year: " << year << "\n"
			<< "ISBN: " << ISBN << "\n";
	}
	// Деструктор
	~Book()
	{
		delete[] ISBN;
	}
private:

	std::string title;
	std::string	author;
	int year;
	char* ISBN;


};