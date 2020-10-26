#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "RarefiedMatrix.h"
using namespace std;

/**
\brief A template class which can save a matrix of elements of different types and work with these elements

This class has private fields:  rd, st, value
And public methods: Constructor Matrix(vector<vector<T>>& value, int rd, int st) , getRd(), getSt(), getValues(), operator ()(int rd, int st), getValue(T value),
getBookValue(string name), getCharacterValue(string name), addMatrix(Matrix<T>& matr), multiplyMatrix(Matrix<T>& matr), multiplyMatrixByVector(vector<T>& arr), transponeMatrix(),
print(), printBook(), printCharacter(), printRarefy(), destructor ~Matrix()
*/
template<class T>
class Matrix
{
public:
	/**
	\brief A constructor of the class Matrix

	This function taces an adress of double array of template values and numbers of lines and columns of this double array
	and creates an object of the class Matrix
	*/
	Matrix(vector<vector<T>>& value, int rd, int st)
	{
		this->rd = rd;
		this->st = st;
		this->value = value;
	}
	/**
\brief Getter for rd field

This function returns the number of lines of the matrix

*/
	int getRd()
	{
		return rd;
	}
	/**
	\brief Getter for st field

	This function returns the number of columns of the matrix

	*/
	int getSt()
	{
		return st;
	}
	/**
\brief Getter for values field

This function returns values of elements of the matrix

*/
	vector<vector<T>>& getValues()
	{
		return value;
	}
	/// An operator which takes the indexes and returns the value of element with this index
	T& operator ()(int rd, int st)
	{
		return value[rd][st];
	}
	/**
	This function takes the value of element and returns  indexes of this element in matrix
	\warning The value must be present in the matrix
	\warning Don't use for books and characters
	*/
	vector<int> getValue(T value)
	{
		vector<int> ret;///< May be more than 1 element
		for (int i = 0; i < rd; i++)
		{
			for (int j = 0; j < st; j++)
			{
				if (this->value[i][j] == value)
				{
					ret.push_back(i);///< The first index
					ret.push_back(j);///< The second index
				}
			}
		}
		return ret;
	}
	/**
	This function takes the name of the book and returns  indexes of this book in matrix
	\warning The name must be present in the matrix
	*/
	vector<int> getBookValue(string name)
	{
		vector<int> ret;///< two indexes of matrix
		for (int i = 0; i < rd; i++)
		{
			for (int j = 0; j < st; j++)
			{
				if (this->value[i][j].getName() == name)
				{
					ret.push_back(i);///< The first index
					ret.push_back(j);///< The second index
					return ret;
				}
			}
		}		
	}
	/**
	This function takes the name of the character and returns  indexes of this character in matrix
	\warning The name must be present in the matrix
	*/
	vector<int> getCharacterValue(string name)
	{
		vector<int> ret;///< two indexes of matrix
		for (int i = 0; i < rd; i++)
		{
			for (int j = 0; j < st; j++)
			{
				if (this->value[i][j].getName() == name)
				{
					ret.push_back(i);///< The first index
					ret.push_back(j);///< The second index
					return ret;
				}
			}
		}
	}
	/**
	\brief Adding operation for two matrixes

	This function takes the object of another matrix, add this and another matrixes
	and returns matrix-result
	*/
	Matrix<T> addMatrix(Matrix<T>& matr)
	{
		vector<vector<T>> ret;///< For result
		for (int i = 0; i < rd; i++)
		{
			ret.push_back(vector<T>());
			for (int j = 0; j < st; j++)
			{
				ret[i].push_back(this->value[i][j] + matr.value[i][j]);
			}
		}
		Matrix<T> res(ret, rd, st);///< Matrix-result
		return res;
	}
	/**
	\brief Multiplying operation for two matrixes

	This function takes the object of another matrix, multiply this and another matrixes
	and returns matrix-result
	*/
	Matrix<T> multiplyMatrix(Matrix<T>& matr)
	{
		vector<vector<T>> ret;///< For result
		for (int i = 0; i < rd; i++)
		{
			ret.push_back(vector<T>());
			for (int j = 0; j < st; j++)
			{
				T sum = 0;///< An element
				for (int k = 0; k < st; k++)
				{
					sum += this->value[i][k] * matr.value[k][j];
				}
				ret[i].push_back(sum);
			}
		}
		Matrix<T> res(ret, rd, st);///< Matrix-result
		return res;
	}
	/**
	\brief Multiplying operation for  matrix and vector

	This function takes the vector and multiply this matrix to vector
	and returns vector-result
	*/
	vector<T> multiplyMatrixByVector(vector<T>& arr)
	{
		vector<T> ret;///< For result
		for (int i = 0; i < rd; i++)
		{
			T sum = 0;///< An element
			for (int j = 0; j < st; j++)
			{
				sum += this->value[i][j] * arr[j];
			}
			ret.push_back(sum);
		}
		return ret;
	}
	/**
	\brief Transponing operation for  matrix

	This function returns a transponed matrix
	
	*/
	Matrix<T> transponeMatrix()
	{
		vector<vector<T>> ret;///< For result
		for (int i = 0; i < rd; i++)
		{
			ret.push_back(vector<T>());
			for (int j = 0; j < st; j++)
			{
				ret[i].push_back(this->value[j][i]);///< Changing indexes
			}
		}
		Matrix<T> res(ret, rd, st);///< Matrix-result
		return res;
	}
	/**
	This function puts out into console all the values of the matrix
	\warning Don't use for books and characters
	*/
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
	/**
	This function puts out into console all the values of the matrix
	\warning  Use for books only
	*/
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
	/**
	This function puts out into console all the values of the matrix
	\warning  Use for characters only
	*/
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
	/**
	This function puts out into console the rarefied form of the matrix
	\warning Only for int, double and bool types
	*/
	void printRarefy()
	{
		RarefiedMatrix<T> rar(this->value);///< An object of class RarefiedMatrix
		rar.print();///<A method of class RarefiedMatrix
	}
	/// Destructor of the class Matrix
	~Matrix()
	{

	}
private:
	int rd, st;///< indexes of matrix
	vector<vector<T>> value;///< values of elements
};

