#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

/**
\brief A template class for saving matrix in rarefied form

This class has private fields: array of non-0 elements, array of column-indexes of non-0 elements, array of pointers on non-0 elements
And public methods: Constructor RarefiedMatrix(vector<vector<int>>& value), constructor RarefiedMatrix(vector<vector<double>>& value),
constructor RarefiedMatrix(vector<vector<bool>>& value), print(), destructor ~RarefiedMatrix()
\warning Use only int, double and bool types

*/
template<class T>
class RarefiedMatrix
{
public:
	/**
	\brief A constructor of RarefiedMatrix

	This function taces an adress of matrix of int values
	and create a matrix in rarefied form

	*/
	RarefiedMatrix(vector<vector<int>>& value)
	{
		for (int i = 0; i < value.size(); i++)
		{
			this->pointers.push_back(this->value.size());
			for (int j = 0; j < value[i].size(); j++)
			{
				if (value[i][j] != 0)
				{
					this->value.push_back(value[i][j]);///< non-0 element
					this->cols.push_back(j);///< non-0 element column-index
				}
			}
		}
		this->pointers.push_back(this->value.size()); ///<pointers on non - 0 element
	}
	/**
	\brief A constructor of RarefiedMatrix

	This function taces an adress of matrix of double values
	and create a matrix in rarefied form

	*/
	RarefiedMatrix(vector<vector<double>>& value)
	{
		for (int i = 0; i < value.size(); i++)
		{
			this->pointers.push_back(this->value.size());
			for (int j = 0; j < value[i].size(); j++)
			{
				if (value[i][j] != 0)
				{
					this->value.push_back(value[i][j]);///< non-0 element
					this->cols.push_back(j);///< non-0 element column-index
				}
			}
		}
		this->pointers.push_back(this->value.size());///<pointers on non - 0 element
	}
	/**
	\brief A constructor of RarefiedMatrix

	This function taces an adress of matrix of bool values
	and create a matrix in rarefied form

	*/
	RarefiedMatrix(vector<vector<bool>>& value)
	{
		for (int i = 0; i < value.size(); i++)
		{
			this->pointers.push_back(this->value.size());
			for (int j = 0; j < value[i].size(); j++)
			{
				if (value[i][j] != false)
				{
					this->value.push_back(value[i][j]);///< non-0 element
					this->cols.push_back(j);///< non-0 element column-index
				}
			}
		}
		this->pointers.push_back(this->value.size());///<pointers on non - 0 element
	}
	/// This function puts out into console the rarefied form of the matrix
	void print()
	{
		for (int i = 0; i < value.size(); i++)
		{
			cout << value[i] << "\t";
		}
		cout << endl;
		for (int i = 0; i < cols.size(); i++)
		{
			cout << cols[i] << "\t";
		}
		cout << endl;
		for (int i = 0; i < pointers.size(); i++)
		{
			cout << pointers[i] << "\t";
		}
		cout << endl;
	}
	/// Destructor of the class RarefiedMatrix
	~RarefiedMatrix()
	{

	}
private:
	vector<T> value;///< non-0 elements
	vector<int> cols;///< non-0 elements' column-indexes
	vector<int> pointers;///< pointers on non-0 elements
};

