#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "RarefiedMatrix.h"
using namespace std;


template<class T>
class Matrix
{
public:
	Matrix(vector<vector<T>>& value, int rd, int st)
	{
		this->rd = rd;
		this->st = st;
		this->value = value;
	}
	int getRd()
	{
		return rd;
	}
	int getSt()
	{
		return st;
	}
	vector<vector<T>>& getValues()
	{
		return value;
	}
	T& operator ()(int rd, int st)
	{
		return value[rd][st];
	}
	vector<int> getValue(T value)
	{
		vector<int> ret;
		for (int i = 0; i < rd; i++)
		{
			for (int j = 0; j < st; j++)
			{
				if (this->value[i][j] == value)
				{
					ret.push_back(i);
					ret.push_back(j);
				}
			}
		}
		return ret;
	}
	vector<int> getBookValue(string name)
	{
		vector<int> ret;
		for (int i = 0; i < rd; i++)
		{
			for (int j = 0; j < st; j++)
			{
				if (this->value[i][j].getName() == name)
				{
					ret.push_back(i);
					ret.push_back(j);
					return ret;
				}
			}
		}		
	}
	vector<int> getCharacterValue(string name)
	{
		vector<int> ret;
		for (int i = 0; i < rd; i++)
		{
			for (int j = 0; j < st; j++)
			{
				if (this->value[i][j].getName() == name)
				{
					ret.push_back(i);
					ret.push_back(j);
					return ret;
				}
			}
		}
	}
	Matrix<T> addMatrix(Matrix<T>& matr)
	{
		vector<vector<T>> ret;
		for (int i = 0; i < rd; i++)
		{
			ret.push_back(vector<T>());
			for (int j = 0; j < st; j++)
			{
				ret[i].push_back(this->value[i][j] + matr.value[i][j]);
			}
		}
		Matrix<T> res(ret, rd, st);
		return res;
	}
	Matrix<T> multiplyMatrix(Matrix<T>& matr)
	{
		vector<vector<T>> ret;
		for (int i = 0; i < rd; i++)
		{
			ret.push_back(vector<T>());
			for (int j = 0; j < st; j++)
			{
				int sum = 0;
				for (int k = 0; k < st; k++)
				{
					sum += this->value[i][k] * matr.value[k][j];
				}
				ret[i].push_back(sum);
			}
		}
		Matrix<T> res(ret, rd, st);
		return res;
	}
	vector<T> multiplyMatrixByVector(vector<T>& arr)
	{
		vector<T> ret;
		for (int i = 0; i < rd; i++)
		{
			int sum = 0;
			for (int j = 0; j < st; j++)
			{
				sum += this->value[i][j] * arr[j];
			}
			ret.push_back(sum);
		}
		return ret;
	}
	Matrix<T> transponeMatrix()
	{
		vector<vector<T>> ret;
		for (int i = 0; i < rd; i++)
		{
			ret.push_back(vector<T>());
			for (int j = 0; j < st; j++)
			{
				ret[i].push_back(this->value[j][i]);
			}
		}
		Matrix<T> res(ret, rd, st);
		return res;
	}
	void print()
	{
		for (int i = 0; i < this->rd; i++)
		{
			for (int j = 0; j < this->st; j++)
			{
				cout << this->value[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void printBook()
	{
		for (int i = 0; i < rd; i++)
		{
			for (int j = 0; j < st; j++)
			{
				this->value[i][j].print();
			}
			cout << endl << endl;
		}
	}
	void printCharacter()
	{
		for (int i = 0; i < rd; i++)
		{
			for (int j = 0; j < st; j++)
			{
				this->value[i][j].print();
			}
			cout << endl << endl;
		}
	}
	void printRarefy()
	{
		RarefiedMatrix<T> rar(this->value);
		rar.print();
	}
	~Matrix()
	{

	}
private:
	int rd, st;
	vector<vector<T>> value;
};

