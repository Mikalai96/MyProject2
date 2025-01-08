#pragma once
#include <iostream>
#include <string>
#include <cstring>

class Book
{
public:
	
	Book();// Конструктор по умолчанию
	Book(const std::string& bTitle, const std::string& bAuthor, int bYear, const char* bISBN); // Конструктор с параметрами
	Book(const Book& other);// Конструктор копирования
	// Геттеры 
	std::string getTitle() const;
	std::string getAuthor() const;
	int getYear() const;
	const char* getISBN() const;
	void printInfo() const;// Метод вывода инфо о книге
	~Book();// Деструктор
	
private:


	std::string title;
	std::string	author;
	int year;
	char* ISBN;

};