#include "BookSerie.h"

/**
\brief Constructor of the class BookSerie

This function takes the information about books from the file
and makes an object of the class BookSerie from the serial books

*/

BookSerie::BookSerie()
{
	vector<Book> books;///< An array of all books from the file
	for (int i = 1; i <= Book::sizeofBooksFile(); i++)
	{
		Book knyha("Books.txt", i);///< Constructor for Book
		books.push_back(knyha);
	}
	vector<vector<Book>> series;///< A matrix in which every line is for one serie of books
	int lich = 0;///< Counter
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getSerie() == "Не серiйна")
		{
			continue;
		}
		else
		{
			bool repeat = false;///< Logical variable to avoid printing the same book twice
			for (int j = 0; j < i; j++)
			{
				if (books[i].getSerie() == books[j].getSerie())
				{
					repeat = true;
				}
			}

			///An array for every serie

			if (!repeat)
			{
				series.push_back(vector<Book>());
				series[lich].push_back(books[i]);
				lich++;
			}
		}
	}
	/// Adding books to arrays of series
	for (int i = 0; i < books.size(); i++)
	{
		for (int j = 0; j < series.size(); j++)
		{
			if ((books[i].getSerie() == series[j][0].getSerie()) && (books[i].getName() != series[j][0].getName()))
			{
				series[j].push_back(books[i]);
			}
		}
	}
	/// Here we sort books, using their year of publishing. The year increases 
	for (int i = 0; i < series.size(); i++)
	{
		for (int j = 0; j < series[i].size(); j++)
		{
			for (int k = j + 1; k < series[i].size(); k++)
			{
				if (series[i][j].getYear() > series[i][k].getYear())
				{
					Book temp = series[i][j];
					series[i][j] = series[i][k];
					series[i][k] = temp;
				}
			}
		}
	}
	this->series = series;///< the result
}

/** 
This function takes the index from console 
and returns the bookserie with this index
*/
vector<Book>& BookSerie::getSerie(int index)
{
	return series[index];
}

/// This function puts out into console all bookseries
void BookSerie::print()
{
	/// Putting out series of books into console
	for (int i = 0; i < series.size(); i++)
	{
		for (int j = 0; j < series[i].size(); j++)
		{
			cout << series[i][j].getName() << "\t\t";
		}
		cout << endl;
	}
}