#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

/**
\brief A class which saves information about the book and can work with it

This class has private fields: id, name, authors, year, pages, anotation, genre, serie
And public methods: constructor Book(string filename, int id), getId(), getName(), getAuthors(), getYear(), getPages(), getAnotation(), getGenre(), getSerie(), print(), printSeries(), sizeofBooksFile(), destructor ~Book()

*/
class Book
{
public:
	/// Constructor of class Book
	Book(string filename, int id);
	/// Getter for id field
	int getId();
	/// getter for name field
	string& getName();
	/// getter for authors field
	string& getAuthors();
	/// getter for year field
	int getYear();
	/// getter for pages field
	int getPages();
	/// getter for anotation field
	string& getAnotation();
	/// getter for genre field
	string& getGenre();
	/// getter for serie field
	string& getSerie();
	/// print the whole information about the book
	void print();
	/// print all series of books
	void printSeries();
	/// get the size of your file with books
    static int sizeofBooksFile();
	/// destructor
	~Book();
private:
	int id; ///< id of the book
	string name; ///< name of the book
	string authors; ///< authors of the book
	int year; ///< year of the book's printing
	int pages; ///< number of pages of the book
	string anotation; ///< short description of the plot
	string genre; ///< genre of the book
	string serie; ///< show if the book is in serie and which serie is it
};
