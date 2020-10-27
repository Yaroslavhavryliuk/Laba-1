#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Book.h"
using namespace std;

/**
\brief A class which saves information about the character of book and can work with it

This class has private fields: id, name, booksNumber, booknames, status
And public methods: constructor Character(string filename, int id), getId(), getName(), getBooksNumber(), getBookNames(), getStatus(),  print(),  sizeofCharactersFile(), destructor ~Character()

*/
class Character
{
public:
	/// Constructor of class Character
	Character(string filename, int id);
	/// Getter for id field
	int getId();
	/// Getter for name field
	string& getName();
	/// Getter for BooksNumber field
	int getBooksNumber();
	/// Getter for BookNames field
	vector<Book>& getBooksPart();
	/// Getter for status field
	vector<string>& getStatus();
	/// print the whole information about the character
	void print();
	/// get the size of your file with characters
	static int sizeofCharactersFile();
	/// destructor
	~Character();
private:
	int id;///< id of the character
	string name;///< name of the character
	int booksNumber;///< the number of books in which character is used
	vector<Book> bookpart;///< books in which character is used
	vector<string> status;/// status of character in every book
};
