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
	vector<Book>& BookSeries();
And public methods: constructor BookSeries(), getSeries(int index), print()

*/
class BookSeries
{
public:
	/// Constructor of the class BookSeries
	BookSeries();
	/// A function for getting a series by its index
	vector<Book>& getSeries(int index);
	/// Print all the series of books
	void print();
private:
	vector<vector<Book>> series;///< All the series of books from the file
};