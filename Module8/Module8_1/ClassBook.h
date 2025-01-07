#pragma once
#include <iostream>
#include <string>
#include <cstring>

class Book
{
public:
	
	Book();// ����������� �� ���������
	Book(const std::string& bTitle, const std::string& bAuthor, int bYear, const char* bISBN); // ����������� � �����������
	Book(const Book& other);// ����������� �����������
	// ������� 
	std::string getTitle() const;
	std::string getAuthor() const;
	int getYear() const;
	const char* getISBN() const;
	void printInfo() const;// ����� ������ ���� � �����
	~Book();// ����������
	
private:

	std::string title;
	std::string	author;
	int year;
	char* ISBN;

};