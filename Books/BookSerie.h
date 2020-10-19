#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Book.h"
using namespace std;

/** 
\brief A class which describes series of books

This class has private field: series
	vector<Book>& BookSerie();
And public methods: constructor BookSerie(), getSerie(int index), print()

*/
class BookSerie
{
public:
	/// Constructor of the class BookSerie
	BookSerie();
	/// A function for getting a serie by its index
	vector<Book>& getSerie(int index);
	/// Print all the series of books
	void print();
private:
	vector<vector<Book>> series;///< All the series of books from the file
};