#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*template<class T>
class Element
{
public:
	Element();
	void setValue(T value);
	T getValue();
private:
	T value;
};*/

template<class T>
class Matrix
{
public:
	Matrix(T** value, int rd, int st)
	{
		this->rd = rd;
		this->st = st;
		this->value = new T*[rd];
		for (int i = 0; i < rd; i++)
		{
			this->value[i] = new T[st];
		}
		for (int i = 0; i < rd; i++)
		{
			for (int j = 0; j < st; j++)
			{
				this->value[i][j] = value[i][j];
			}
		}
	}
	int getRd()
	{
		return rd;
	}
	int getSt()
	{
		return st;
	}
	T** getValues()
	{
		return value;
	}
	~Matrix()
	{
		for (int i = 0; i < rd; i++)
		{
			delete[] value[i];
		}
		delete[] value;
	}
private:
	int rd, st;
	T** value;
};