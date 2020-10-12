#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


template<class T>
class RarefiedList
{
public:
	RarefiedList(vector<int>& value)
	{
		for (int i = 0; i < value.size(); i++)
		{
			if (value[i] != 0)
			{
				this->value.push_back(value[i]);
				this->position.push_back(i);
			}
		}
	}
	RarefiedList(vector<double>& value)
	{
		for (int i = 0; i < value.size(); i++)
		{
			if (value[i] != 0)
			{
				this->value.push_back(value[i]);
				this->position.push_back(i);
			}
		}
	}
	RarefiedList(vector<bool>& value)
	{
		for (int i = 0; i < value.size(); i++)
		{
			if (value[i] != false)
			{
				this->value.push_back(value[i]);
				this->position.push_back(i);
			}
		}
	}
	/*RarefiedList(vector<char>& value)
	{
		for (int i = 0; i < value.size(); i++)
		{
			if (value[i] != ' ')
			{
				this->value.push_back(value[i]);
				this->position.push_back(i);
			}
		}
	}*/
	/*RarefiedList(vector<string>& value)
	{
		for (int i = 0; i < value.size(); i++)
		{
			if (value[i] != " ")
			{
				this->value.push_back(value[i]);
				this->position.push_back(i);
			}
		}
	}*/
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
	~RarefiedList()
	{

	}
private:
	vector<T> value;
	vector<int>position;
};
