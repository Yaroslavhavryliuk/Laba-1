#include "Character.h"



/**
\brief Constructor of the class Character

This function takes the name of file with characters and the id of the selected character in the file
\warning Check if the character with this id exists in file

This function creates an object of class Character
*/

Character::Character(string filename, int id)
{
	ifstream finc;
	finc.open(filename);
	/// exception for error of opening the file
	if (!finc.is_open())
	{
		cout << "Помилка вiдкриття файлу з персонажами!" << endl;
	}
	else
	{
		if (finc.eof())
		{
			cout << "Файл пустий" << endl;
		}
		string st;///< variable for reading the file
		int num;
		for (int i = 1; i < id; i++)
		{

			getline(finc, st);
			getline(finc, st);
			finc >> num;
			getline(finc, st);
			///reading books
			for (int j = 0; j < num; j++)
			{
				getline(finc, st);
				getline(finc, st);
			}
			/// exception for the wrong input(id)
			if (finc.eof())
			{
				cout << "Не iснує персонажа з таким id" << endl;
				break;
			}
		}
		/// creating an object of Character
		char ch;
		finc >> this->id;
		finc >> ch;
		getline(finc, this->name);
		finc >> this->booksNumber;
		finc >> ch;
		string str;
		vector<Book> allbooks;
		for (int i = 1; i <= Book::sizeofBooksFile(); i++)
		{
			Book b("Books.txt", i);
			allbooks.push_back(b);
		}
		for (int i = 0; i < this->booksNumber; i++)
		{
			getline(finc, str);
			for (int i = 0; i < allbooks.size(); i++)
			{
				if (allbooks[i].getName() == str)
				{
					bookpart.push_back(allbooks[i]);
				}
			}
			getline(finc, str);
			status.push_back(str);
		}
		finc.close();
	}
}
/**
\brief Getter for id field

This function returns the id of the character

*/
int Character::getId()
{
	return id;
}
/**
\brief Getter for name field

This function returns the name of the Character

*/

string& Character::getName()
{
	return name;
}
/**
\brief Getter for books number

This function returns the number of books in which character is used
*/
int Character::getBooksNumber()
{
	return booksNumber;
}
/**
\brief Getter for books' names

This function returns books in which character is used
*/
vector<Book>& Character::getBooksPart()
{
	return bookpart;
}
/**
\brief Getter for status

This function returns the status of character in every book in which character is used
*/
vector<string>& Character::getStatus()
{
	return status;
}
/**
\brief Print all information about the character

This function puts out into console the whole information
from all of fields of the character

*/
void Character::print()
{
	cout << this->id << endl;
	cout << this->name << endl;
	cout << this->booksNumber << endl;
	for (int i = 0; i < this->booksNumber; i++)
	{
		cout << this->bookpart[i].getName() << "\t\t" << this->status[i] << endl;
	}
}
/**
\brief The number of characters in file

This function returns the number of characters in the character file

*/
int Character::sizeofCharactersFile()
{
	ifstream fincs;
	fincs.open("Characters.txt");
	if (!fincs.is_open())
	{
		cout << "Помилка вiдкриття файлу з книгами!" << endl;
		return -1;
	}
	else
	{
		if (fincs.eof())
		{
			fincs.close();
			return 0;
		}
		else
		{
			int count = 0;;
			string st;
			int num;
			while (!fincs.eof())
			{
				getline(fincs, st);
				getline(fincs, st);
				fincs >> num;
				getline(fincs, st);
				for (int j = 0; j < num; j++)
				{
					getline(fincs, st);
					getline(fincs, st);
				}
				count++;
			}
			fincs.close();
			return count - 1;
		}
	}
}

/// Destructor of the class Character
Character::~Character()
{

}


