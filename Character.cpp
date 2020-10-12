#include "Character.h"


Character::Character(string filename, int id)
{
	ifstream finc;
	finc.open(filename);
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
		string st;
		int num;
		for (int i = 1; i < id; i++)
		{

			getline(finc, st);
			getline(finc, st);
			finc >> num;
			getline(finc, st);
			for (int j = 0; j < num; j++)
			{
				getline(finc, st);
				getline(finc, st);
			}
			if (finc.eof())
			{
				cout << "Не iснує персонажа з таким id" << endl;
				break;
			}
		}

		char ch;
		finc >> this->id;
		finc >> ch;
		getline(finc, this->name);
		finc >> this->booksNumber;
		finc >> ch;
		string str;
		for (int i = 0; i < this->booksNumber; i++)
		{
			getline(finc, str);
			booknames.push_back(str);
			getline(finc, str);
			status.push_back(str);
		}
		finc.close();
	}
}

int Character::getId()
{
	return id;
}

string& Character::getName()
{
	return name;
}

int Character::getBooksNumber()
{
	return booksNumber;
}

vector<string>& Character::getBookNames()
{
	return booknames;
}

vector<string>& Character::getStatus()
{
	return status;
}

void Character::print()
{
	cout << this->id << endl;
	cout << this->name << endl;
	cout << this->booksNumber << endl;
	for (int i = 0; i < this->booksNumber; i++)
	{
		cout << this->booknames[i] << "\t\t" << this->status[i] << endl;
	}
}

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


Character::~Character()
{

}


