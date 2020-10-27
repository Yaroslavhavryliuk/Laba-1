#include "Book.h"
#include "Character.h"
#include "List.h"
#include "Matrix.h"
#include "RarefiedList.h"
#include "RarefiedMatrix.h"
#include "BookSeries.h"


;
int main()
{
	//INTERFACE
	setlocale(LC_ALL, "ukr");
	int a;// Variable for input
	bool resumeM = true;// Variable for ending the program
	cout << "What would you like to work with? Choose the number:" << endl << "1.List" << endl << "2.Matrix" << endl << "3.Book" << endl << "4.Character" << endl <<"5.BookSerie"<<endl<< "0.End the program" << endl;
	while (resumeM)
	{
		cin >> a;

		if (a == 0)
		{
			resumeM = false;// End the program
		}
		if (a == 1)// Work with List
		{
			cout << "Enter the type. Choose the number:" << endl << "1.Int number(int)" << endl << "2. Real number(double)" << endl << "3.Logical type(bool)" << endl << "4.String type(string)" << endl << "5.Book type(book)" << endl << "6.Character type(character)" << endl;
			int type;
			cin >> type;
			if (type == 1)// List of integers
			{
				// Show all the abilities of class List for integers
				cout << "Enter the size" << endl;
				int size;
				cin >> size;
				vector<int> value;
				int read;
				cout << "Enter values" << endl;
				for (int i = 0; i < size; i++)
				{
					cin >> read;
					value.push_back(read);
				}
				List<int> lst(value, size);
				cout << "Size: " << lst.getSize() << endl;
				cout << "-----------------------------------" << endl;
				cout << "Values: ";
				for (int i = 0; i < lst.getSize(); i++)
				{
					cout << lst.getValues()[i] << "\t";
				}
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << "Enter the value for getting its index" << endl;
				int index;
				cin >> index;
				cout << "The index: ";
				for (int i = 0; i < lst.getValue(index).size(); i++)
				{
					cout << lst.getValue(index)[i] << "\t";
				}
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << "The whole list printed: " << endl;
				lst.print();
				cout << "-----------------------------------" << endl;
				cout << "List in rarefied form: " << endl;
				lst.printRarefy();
			}
			if (type == 2)// List of doubles
			{
				// Show all the abilities of class List for doubles
				cout << "Enter the size" << endl;
				int size;
				cin >> size;
				vector<double> value;
				double read;
				cout << "Enter values" << endl;
				for (int i = 0; i < size; i++)
				{
					cin >> read;
					value.push_back(read);
				}
				List<double> lst(value, size);
				cout << "Size: " << lst.getSize() << endl;
				cout << "-----------------------------------" << endl;
				cout << "Values: ";
				for (int i = 0; i < lst.getSize(); i++)
				{
					cout << lst.getValues()[i] << "\t";
				}
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << "Enter the value for getting its index" << endl;
				double index;
				cin >> index;
				cout << "The index: ";
				for (int i = 0; i < lst.getValue(index).size(); i++)
				{
					cout << lst.getValue(index)[i] << "\t";
				}
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << "The whole list printed: " << endl;
				lst.print();
				cout << "-----------------------------------" << endl;
				cout << "List in rarefied form: " << endl;
				lst.printRarefy();
			}
			if (type == 3)// List of logical variables
			{
				// Show all the abilities of class List for logical variables
				cout << "Enter the size" << endl;
				int size;
				cin >> size;
				vector<bool> value;
				bool read;
				cout << "Enter values" << endl;
				for (int i = 0; i < size; i++)
				{
					cin >> read;
					value.push_back(read);
				}
				List<bool> lst(value, size);
				cout << "Size: " << lst.getSize() << endl;
				cout << "-----------------------------------" << endl;
				cout << "Values: ";
				for (int i = 0; i < lst.getSize(); i++)
				{
					cout << lst.getValues()[i] << "\t";
				}
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << "Enter the value for getting its index" << endl;
				double index;
				cin >> index;
				cout << "The index: ";
				for (int i = 0; i < lst.getValue(index).size(); i++)
				{
					cout << lst.getValue(index)[i] << "\t";
				}
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << "The whole list printed: " << endl;
				lst.print();
				cout << "-----------------------------------" << endl;
				cout << "List in rarefied form: " << endl;
				lst.printRarefy();
			}
			if (type == 4)// List of strings
			{
				// Show all the abilities of class List for strings
				cout << "Enter the size" << endl;
				int size;
				cin >> size;
				vector<string> value;
				string read;
				cout << "Enter values" << endl;
				for (int i = 0; i < size; i++)
				{
					cin >> read;
					value.push_back(read);
				}
				List<string> lst(value, size);
				cout << "Size: " << lst.getSize() << endl;
				cout << "-----------------------------------" << endl;
				cout << "Values: ";
				for (int i = 0; i < lst.getSize(); i++)
				{
					cout << lst.getValues()[i] << "\t";
				}
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << "Enter the value for getting its index" << endl;
				string index;
				cin >> index;
				cout << "The index: ";
				for (int i = 0; i < lst.getValue(index).size(); i++)
				{
					cout << lst.getValue(index)[i] << "\t";
				}
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << "The whole list printed: " << endl;
				lst.print();
			}
			if (type == 5)// List of books
			{
				// Show all the abilities of class List for books
				cout << "Enter the size" << endl;
				int size;
				cin >> size;
				vector<Book> value;
				int read;
				cout << "The size of file with books is: " << Book::sizeofBooksFile() << endl;
				cout << "Put indexes(id) of books. They should be from 1 to the size of file!" << endl;
				for (int i = 0; i < size; i++)
				{
					cin >> read;
					Book b("Books.txt", read);
					value.push_back(b);
				}
				List<Book> lst(value, size);
				cout << "Size: " << lst.getSize() << endl;
				cout << "-----------------------------------" << endl;
				cout << "Values: ";
				for (int i = 0; i < lst.getSize(); i++)
				{
					cout << lst.getValues()[i].getName() << "\t\t";
				}
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << "The whole list printed: " << endl;
				lst.printBook();
			}
			if (type == 6)// List of characters
			{
				// Show all the abilities of class List for characters
				cout << "Enter the size" << endl;
				int size;
				cin >> size;
				vector<Character> value;
				int read;
				cout << "The size of file with characters is: " << Character::sizeofCharactersFile() << endl;
				cout << "Put indexes(id) of characters. They should be from 1 to the size of file!" << endl;
				for (int i = 0; i < size; i++)
				{
					cin >> read;
					Character ch("Characters.txt", read);
					value.push_back(ch);
				}
				List<Character> lst(value, size);
				cout << "Size: " << lst.getSize() << endl;
				cout << "-----------------------------------" << endl;
				cout << "Values: ";
				for (int i = 0; i < lst.getSize(); i++)
				{
					cout << lst.getValues()[i].getName() << "\t\t";
				}
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << "The whole list printed: " << endl;
				lst.printCharacter();
			}
		}
		if (a == 2)// Work with Matrix
		{
			cout << "Enter the type. Choose the number:" << endl << "1.Int number(int)" << endl << "2. Real number(double)" << endl << "3.Logical type(bool)" << endl << "4.String type(string)" << endl << "5.Book type(book)" << endl << "6.Character type(character)" << endl;
			int type;
			cin >> type;
			if (type == 1)// Matrix of integers
			{
				// Show all the abilities of class Matrix for integers
				cout << "Enter the number of lines" << endl;
				int lines;
				cin >> lines;
				cout << "Enter the number of columns" << endl;
				int columns;
				cin >> columns;
				vector<vector<int>> value;
				int read;
				cout << "Enter values" << endl;
				for (int i = 0; i < lines; i++)
				{
					value.push_back(vector<int>());
					for (int j = 0; j < columns; j++)
					{
						cin >> read;
						value[i].push_back(read);
					}
				}
				Matrix<int> matr(value, lines, columns);
				cout << "Lines: " << matr.getRd() << endl;
				cout << "-----------------------------------" << endl;
				cout << "Columns: " << matr.getSt() << endl;
				cout << "-----------------------------------" << endl;
				cout << "Values: " << endl;
				for (int i = 0; i < matr.getRd(); i++)
				{
					for (int j = 0; j < matr.getSt(); j++)
					{
						cout << matr.getValues()[i][j] << "\t";
					}
					cout << endl;
				}
				cout << "-----------------------------------" << endl;
				cout << "Enter the value for getting its indexes" << endl;
				int index;
				cin >> index;
				cout << "Indexes: ";
				for (int i = 0; i < matr.getValue(index).size(); i++)
				{
					cout << matr.getValue(index)[i] << " ";
					i++;
					cout << matr.getValue(index)[i] << "\t";
				}
				cout << endl;
				cout << "-----------------------------------" << endl;
				vector<vector<int>> value2;
				int read2;
				cout << "Enter the values of the second Matrix for operations. The size must be the same!" << endl;
				for (int i = 0; i < lines; i++)
				{
					value2.push_back(vector<int>());
					for (int j = 0; j < columns; j++)
					{
						cin >> read2;
						value2[i].push_back(read2);
					}
				}
				Matrix<int> matr2(value2, lines, columns);
				cout << "The first Matrix: " << endl;
				matr.print();
				cout << "-----------------------------------" << endl;
				cout << "The second Matrix: " << endl;
				matr2.print();
				cout << "-----------------------------------" << endl;
				cout << "The sum of Matrixes: " << endl;
				matr.addMatrix(matr2).print();
				cout << "-----------------------------------" << endl;
				cout << "The multiply of Matrixes: " << endl;
				matr.multiplyMatrix(matr2).print();
				cout << "-----------------------------------" << endl;
				cout << "Enter the values of vector for multiplying. The size of lines!" << endl;
				vector<int> value3;
				int read3;
				cout << "Enter values" << endl;
				for (int i = 0; i < lines; i++)
				{
					cin >> read3;
					value3.push_back(read3);
				}
				cout << "The multiply of Matrix and vector: " << endl;
				for (int i = 0; i < matr.multiplyMatrixByVector(value3).size(); i++)
				{
					cout << matr.multiplyMatrixByVector(value3)[i] << "\t";
				}
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << "Transposed Matrix: " << endl;
				matr.transponeMatrix().print();
				cout << "-----------------------------------" << endl;
				cout << "Rarefied Matrix: " << endl;
				matr.printRarefy();
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << "The whole matrix printed: " << endl;
				matr.print();
			}
			if (type == 2)// Matrix of doubles
			{
				// Show all the abilities of class Matrix for doubles
				cout << "Enter the number of lines" << endl;
				int lines;
				cin >> lines;
				cout << "Enter the number of columns" << endl;
				int columns;
				cin >> columns;
				vector<vector<double>> value;
				double read;
				cout << "Enter values" << endl;
				for (int i = 0; i < lines; i++)
				{
					value.push_back(vector<double>());
					for (int j = 0; j < columns; j++)
					{
						cin >> read;
						value[i].push_back(read);
					}
				}
				Matrix<double> matr(value, lines, columns);
				cout << "Lines: " << matr.getRd() << endl;
				cout << "-----------------------------------" << endl;
				cout << "Columns: " << matr.getSt() << endl;
				cout << "-----------------------------------" << endl;
				cout << "Values: " << endl;
				for (int i = 0; i < matr.getRd(); i++)
				{
					for (int j = 0; j < matr.getSt(); j++)
					{
						cout << matr.getValues()[i][j] << "\t";
					}
					cout << endl;
				}
				cout << "-----------------------------------" << endl;
				cout << "Enter the value for getting its indexes" << endl;
				double index;
				cin >> index;
				cout << "Indexes: ";
				for (int i = 0; i < matr.getValue(index).size(); i++)
				{
					cout << matr.getValue(index)[i] << " ";
					i++;
					cout << matr.getValue(index)[i] << "\t";
				}
				cout << endl;
				cout << "-----------------------------------" << endl;
				vector<vector<double>> value2;
				double read2;
				cout << "Enter the values of the second Matrix for operations. The size must be the same!" << endl;
				for (int i = 0; i < lines; i++)
				{
					value2.push_back(vector<double>());
					for (int j = 0; j < columns; j++)
					{
						cin >> read2;
						value2[i].push_back(read2);
					}
				}
				Matrix<double> matr2(value2, lines, columns);
				cout << "The first Matrix: " << endl;
				matr.print();
				cout << "-----------------------------------" << endl;
				cout << "The second Matrix: " << endl;
				matr2.print();
				cout << "-----------------------------------" << endl;
				cout << "The sum of Matrixes: " << endl;
				matr.addMatrix(matr2).print();
				cout << "-----------------------------------" << endl;
				cout << "The multiply of Matrixes: " << endl;
				matr.multiplyMatrix(matr2).print();
				cout << "-----------------------------------" << endl;
				cout << "Enter the values of vector for multiplying. The size of lines!" << endl;
				vector<double> value3;
				double read3;
				cout << "Enter values" << endl;
				for (int i = 0; i < lines; i++)
				{
					cin >> read3;
					value3.push_back(read3);
				}
				cout << "The multiply of Matrix and vector: " << endl;
				for (int i = 0; i < matr.multiplyMatrixByVector(value3).size(); i++)
				{
					cout << matr.multiplyMatrixByVector(value3)[i] << "\t";
				}
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << "Transposed Matrix: " << endl;
				matr.transponeMatrix().print();
				cout << "-----------------------------------" << endl;
				cout << "Rarefied Matrix: " << endl;
				matr.printRarefy();
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << "The whole matrix printed: " << endl;
				matr.print();
			}
			if (type == 3)// Matrix of logical variables
			{
				// Show all the abilities of class Matrix for logical variables 
				cout << "Enter the number of lines" << endl;
				int lines;
				cin >> lines;
				cout << "Enter the number of columns" << endl;
				int columns;
				cin >> columns;
				vector<vector<bool>> value;
				bool read;
				cout << "Enter values" << endl;
				for (int i = 0; i < lines; i++)
				{
					value.push_back(vector<bool>());
					for (int j = 0; j < columns; j++)
					{
						cin >> read;
						value[i].push_back(read);
					}
				}
				Matrix<bool> matr(value, lines, columns);
				cout << "Lines: " << matr.getRd() << endl;
				cout << "-----------------------------------" << endl;
				cout << "Columns: " << matr.getSt() << endl;
				cout << "-----------------------------------" << endl;
				cout << "Values: " << endl;
				for (int i = 0; i < matr.getRd(); i++)
				{
					for (int j = 0; j < matr.getSt(); j++)
					{
						cout << matr.getValues()[i][j] << "\t";
					}
					cout << endl;
				}
				cout << "-----------------------------------" << endl;
				cout << "Enter the value for getting its indexes" << endl;
				bool index;
				cin >> index;
				cout << "Indexes: ";
				for (int i = 0; i < matr.getValue(index).size(); i++)
				{
					cout << matr.getValue(index)[i] << " ";
					i++;
					cout << matr.getValue(index)[i] << "\t";
				}
				cout << endl;
				cout << "-----------------------------------" << endl;
				vector<vector<bool>> value2;
				bool read2;
				cout << "Enter the values of the second Matrix for operations. The size must be the same!" << endl;
				for (int i = 0; i < lines; i++)
				{
					value2.push_back(vector<bool>());
					for (int j = 0; j < columns; j++)
					{
						cin >> read2;
						value2[i].push_back(read2);
					}
				}
				Matrix<bool> matr2(value2, lines, columns);
				cout << "The first Matrix: " << endl;
				matr.print();
				cout << "-----------------------------------" << endl;
				cout << "The second Matrix: " << endl;
				matr2.print();
				cout << "-----------------------------------" << endl;
				cout << "The sum of Matrixes: " << endl;
				matr.addMatrix(matr2).print();
				cout << "-----------------------------------" << endl;
				cout << "The multiply of Matrixes: " << endl;
				matr.multiplyMatrix(matr2).print();
				cout << "-----------------------------------" << endl;
				cout << "Enter the values of vector for multiplying. The size of lines!" << endl;
				vector<bool> value3;
				bool read3;
				cout << "Enter values" << endl;
				for (int i = 0; i < lines; i++)
				{
					cin >> read3;
					value3.push_back(read3);
				}
				cout << "The multiply of Matrix and vector: " << endl;
				for (int i = 0; i < matr.multiplyMatrixByVector(value3).size(); i++)
				{
					cout << matr.multiplyMatrixByVector(value3)[i] << "\t";
				}
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << "Transposed Matrix: " << endl;
				matr.transponeMatrix().print();
				cout << "-----------------------------------" << endl;
				cout << "Rarefied Matrix: " << endl;
				matr.printRarefy();
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << "The whole matrix printed: " << endl;
				matr.print();
			}
			if (type == 4)// Matrix of strings
			{
				// Show all the abilities of class Matrix for strings
				cout << "Enter the number of lines" << endl;
				int lines;
				cin >> lines;
				cout << "Enter the number of columns" << endl;
				int columns;
				cin >> columns;
				vector<vector<string>> value;
				string read;
				cout << "Enter values" << endl;
				for (int i = 0; i < lines; i++)
				{
					value.push_back(vector<string>());
					for (int j = 0; j < columns; j++)
					{
						cin >> read;
						value[i].push_back(read);
					}
				}
				Matrix<string> matr(value, lines, columns);
				cout << "Lines: " << matr.getRd() << endl;
				cout << "-----------------------------------" << endl;
				cout << "Columns: " << matr.getSt() << endl;
				cout << "-----------------------------------" << endl;
				cout << "Values: " << endl;
				for (int i = 0; i < matr.getRd(); i++)
				{
					for (int j = 0; j < matr.getSt(); j++)
					{
						cout << matr.getValues()[i][j] << "\t";
					}
					cout << endl;
				}
				cout << "-----------------------------------" << endl;
				cout << "Enter the value for getting its indexes" << endl;
				string index;
				cin >> index;
				cout << "Indexes: ";
				for (int i = 0; i < matr.getValue(index).size(); i++)
				{
					cout << matr.getValue(index)[i] << " ";
					i++;
					cout << matr.getValue(index)[i] << "\t";
				}
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << "The whole matrix printed: " << endl;
				matr.print();
			}
			if (type == 5)// Matrix of books
			{
				// Show all the abilities of class Matrix for books
				cout << "Enter the number of lines" << endl;
				int lines;
				cin >> lines;
				cout << "Enter the number of columns" << endl;
				int columns;
				cin >> columns;
				vector<vector<Book>> value;
				int read;
				cout << "The size of file with books is: " << Book::sizeofBooksFile() << endl;
				cout << "Put indexes(id) of books. They should be from 1 to the size of file!" << endl;
				for (int i = 0; i < lines; i++)
				{
					value.push_back(vector<Book>());
					for (int j = 0; j < columns; j++)
					{
						cin >> read;
						Book b("Books.txt", read);
						value[i].push_back(b);
					}
				}
				Matrix<Book> matr(value, lines, columns);
				cout << "Lines: " << matr.getRd() << endl;
				cout << "-----------------------------------" << endl;
				cout << "Columns: " << matr.getSt() << endl;
				cout << "-----------------------------------" << endl;
				cout << "Values: " << endl;
				for (int i = 0; i < matr.getRd(); i++)
				{
					for (int j = 0; j < matr.getSt(); j++)
					{
						cout << matr.getValues()[i][j].getName() << "\t\t";
					}
					cout << endl;
				}
				cout << "-----------------------------------" << endl;
				cout << "The whole matrix printed: " << endl;
				matr.printBook();
			}
			if (type == 6)// Matrix of characters
			{
				// Show all the abilities of class Matrix for characters
				cout << "Enter the number of lines" << endl;
				int lines;
				cin >> lines;
				cout << "Enter the number of columns" << endl;
				int columns;
				cin >> columns;
				vector<vector<Character>> value;
				int read;
				cout << "The size of file with characters is: " << Character::sizeofCharactersFile() << endl;
				cout << "Put indexes(id) of characters. They should be from 1 to the size of file!" << endl;
				for (int i = 0; i < lines; i++)
				{
					value.push_back(vector<Character>());
					for (int j = 0; j < columns; j++)
					{
						cin >> read;
						Character b("Characters.txt", read);
						value[i].push_back(b);
					}
				}
				Matrix<Character> matr(value, lines, columns);
				cout << "Lines: " << matr.getRd() << endl;
				cout << "-----------------------------------" << endl;
				cout << "Columns: " << matr.getSt() << endl;
				cout << "-----------------------------------" << endl;
				cout << "Values: " << endl;
				for (int i = 0; i < matr.getRd(); i++)
				{
					for (int j = 0; j < matr.getSt(); j++)
					{
						cout << matr.getValues()[i][j].getName() << "\t\t";
					}
					cout << endl;
				}
				cout << "-----------------------------------" << endl;
				cout << "The whole matrix printed: " << endl;
				matr.printCharacter();
			}
		}
		if (a == 3)//Work with class Book
		{
			// Show all the abilities of class Book
			cout << "The size of file with books is: " << Book::sizeofBooksFile() << endl;
			cout << "Create a book and get information about it:" << endl;
			int index;
			cout << "Put index(id) of book. It should be from 1 to the size of file!" << endl;
			cin >> index;
			Book book("Books.txt", index);
			cout << "All information about this book: " << endl;
			book.print();
			cout << "-----------------------------------" << endl;
			cout << "Series of books:" << endl;
			BookSeries books;// bookserie class object
			books.print();
			cout << "-----------------------------------" << endl;
			cout << "Enter the index for getting a books serie. Not more than number of series!" << endl;
			int number;// index for books serie
			cin >> number;
			for (int i = 0; i < books.getSeries(number-1).size(); i++)
			{
				cout << books.getSeries(number-1)[i].getName() << "\t\t";
			}
		}
		if (a == 4)//Work with class Character
		{
			// Show all the abilities of class Character
			cout << "The size of file with characters is: " << Character::sizeofCharactersFile() << endl;
			cout << "Create a character and get information about him:" << endl;
			int index;
			cout << "Put index(id) of character. It should be from 1 to the size of file!" << endl;
			cin >> index;
			Character character("Characters.txt", index);
			cout << "All information about this character: " << endl;
			character.print();
		}
		if (a == 5)// Work with series of books
		{
			// Show all the abilities of class BookSerie
			cout << "All Series of books:" << endl;
			BookSeries series;
			series.print();
			cout << "Enter the index for getting a books serie. Not more than number of series!" << endl;
			int number;// index for books serie
			cin >> number;
			for (int i = 0; i < series.getSeries(number - 1).size(); i++)
			{
				cout << series.getSeries(number - 1)[i].getName() << "\t\t";
			}
		}
	}

	
	return 0;
}

