#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "RarefiedList.h"
using namespace std;
/**
\brief A template class which can save a list of elements of different types and work with these elements

This class has private fields: size, value
And public methods: Constructor List(vector<T>& value, int size), constructor List(), getSize(), getValues(), operator[](int index), getValue(T value),
getBookValue(string name), getCharacterValue(string name), print(), printBook(), printCharacter(), printRarefy(), destructor ~List()
*/
template<class T>
class List
{
public:
	/**
	\brief A constructor of the class List
	
	This function taces an adress of array of template values and the size of this array
	and creates an object of the class List
	*/
	List(vector<T>& value, int size)
	{
		this->size = size;
		this->value = value;
	}
	/// The second constructor without parameters
	List()
	{

	}
	/**
\brief Getter for size field

This function returns the size of the list

*/
	int getSize()
	{
		return size;
	}
	/**
\brief Getter for values field

This function returns values of elements of the list

*/
	vector<T>& getValues()
	{
		return value;
	}
	/// An operator which takes the index and returns the value of element with this index
	T& operator[](int index)
	{
		return value[index];
	}
	/**
	This function takes the value of element and returns an index of this element in list
	\warning The value must be present in the list
	\warning Don't use for books and characters
	*/
	vector<int> getValue(T value)
	{
		vector<int> ret;
		for (int i = 0; i < size; i++)
		{
			if (this->value[i] == value)
			{
				ret.push_back(i);
			}
		}
		return ret;
	}
	/**
	This function takes the name of the book and returns an index of this book in list
	\warning The name must be present in the list
	*/
	int getBookValue(string name)
	{
		for (int i = 0; i < size; i++)
		{
			if (this->value[i].getName() == name)
			{
				return i;
			}
		}
		return 0;
	}
	/**
	This function takes the name of the character and returns an index of this character in list
	\warning The name must be present in the list
	*/
	int getCharacterValue(string name)
	{
		for (int i = 0; i < size; i++)
		{
			if (this->value[i].getName() == name)
			{
				return i;
			}
		}
		return 0;
	}
	/** 
	This function puts out into console all the values of the list 
	\warning Don't use for books and characters
	*/
	void print()
	{
		for (int i = 0; i < this->size; i++)
		{
			cout << this->value[i] << "\t";
		}
		cout << endl;
	}
	/**
	This function puts out into console all the values of the list
	\warning  Use for books only
	*/
	void printBook()
	{
		for (int i = 0; i < this->size; i++)
		{
			this->value[i].print();
		}
		cout << endl;
	}
	/**
	This function puts out into console all the values of the list
	\warning  Use for characters only
	*/
	void printCharacter()
	{
		for (int i = 0; i < this->size; i++)
		{
			this->value[i].print();
		}
		cout << endl;
	}
	/** 
	This function puts out into console the rarefied form of the list
	\warning Only for int, double and bool types
	*/
	void printRarefy()
	{
		RarefiedList<T> rar(this->value);///< An object of class RarefiedList
		rar.print();///<A method of class RarefiedList
	}
	/// Destructor of the class List
	~List()
	{

	}
private:
	int size;///< The size of the list
	vector<T> value;///< Values of elements in list
};



