#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "RarefiedList.h"
using namespace std;

template<class T>
class List
{
public:
	List(vector<T>& value, int size)
	{
		this->size = size;
		this->value = value;
	}
	List()
	{

	}
	int getSize()
	{
		return size;
	}
	vector<T>& getValues()
	{
		return value;
	}
	T& operator[](int index)
	{
		return value[index];
	}
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
	void print()
	{
		for (int i = 0; i < this->size; i++)
		{
			cout << this->value[i] << "\t";
		}
		cout << endl;
	}
	void printBook()
	{
		for (int i = 0; i < this->size; i++)
		{
			this->value[i].print();
		}
		cout << endl;
	}
	void printCharacter()
	{
		for (int i = 0; i < this->size; i++)
		{
			this->value[i].print();
		}
		cout << endl;
	}
	void printRarefy()
	{
		RarefiedList<T> rar(this->value);
		rar.print();
	}
	~List()
	{

	}
private:
	int size;
	vector<T> value;
};



