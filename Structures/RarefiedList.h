#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

/**
\brief A template class for saving list in rarefied form

This class has private fields: array of non-0 elements, array of indexes of non-0 elements
And public methods: Constructor RarefiedList(vector<int>& value), constructor RarefiedList(vector<double>& value),
constructor RarefiedList(vector<bool>& value), print(), destructor ~RarefiedList()
\warning Use only int, double and bool types
*/
template<class T>
class RarefiedList
{
public:
	/**
	\brief A constructor of RarefiedList

	This function taces an adress of array of int values
	and create a list in rarefied form
	
	*/
	RarefiedList(vector<int>& value)
	{
		for (int i = 0; i < value.size(); i++)
		{
			if (value[i] != 0)
			{
				this->value.push_back(value[i]);///< non-0 element
				this->position.push_back(i);///< non-0 element index
			}
		}
	}
	/**
	\brief A constructor of RarefiedList

	This function taces an adress of array of double values
	and create a list in rarefied form

	*/
	RarefiedList(vector<double>& value)
	{
		for (int i = 0; i < value.size(); i++)
		{
			if (value[i] != 0)
			{
				this->value.push_back(value[i]);///< non-0 element
				this->position.push_back(i);///< non-0 element index
			}
		}
	}
	/**
	\brief A constructor of RarefiedList

	This function taces an adress of array of bool values
	and create a list in rarefied form

	*/
	RarefiedList(vector<bool>& value)
	{
		for (int i = 0; i < value.size(); i++)
		{
			if (value[i] != false)
			{
				this->value.push_back(value[i]);///< non-0 element
				this->position.push_back(i);///< non-0 element index
			}
		}
	}
	/// This function puts out into console the rarefied form of the list
	void print()
	{
		for (int i = 0; i < value.size(); i++)
		{
			cout << value[i] << "\t";
		}
		cout << endl;
		for (int i = 0; i < position.size(); i++)
		{
			cout << position[i] << "\t";
		}
		cout << endl;
	}
	/// Destructor of the class RarefiedList
	~RarefiedList()
	{

	}
private:
	vector<T> value;///< non-0 elements
	vector<int>position;///< non-0 elements' indexes
};
