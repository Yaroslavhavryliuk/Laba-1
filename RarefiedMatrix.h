#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


template<class T>
class RarefiedMatrix
{
public:
	RarefiedMatrix(vector<vector<int>>& value)
	{
		for (int i = 0; i < value.size(); i++)
		{
			this->pointers.push_back(this->value.size());
			for (int j = 0; j < value[i].size(); j++)
			{
				if (value[i][j] != 0)
				{
					this->value.push_back(value[i][j]);
					this->cols.push_back(j);
				}
			}
		}
		this->pointers.push_back(this->value.size());
	}
	RarefiedMatrix(vector<vector<double>>& value)
	{
		for (int i = 0; i < value.size(); i++)
		{
			this->pointers.push_back(this->value.size());
			for (int j = 0; j < value[i].size(); j++)
			{
				if (value[i][j] != 0)
				{
					this->value.push_back(value[i][j]);
					this->cols.push_back(j);
				}
			}
		}
		this->pointers.push_back(this->value.size());
	}
	RarefiedMatrix(vector<vector<bool>>& value)
	{
		for (int i = 0; i < value.size(); i++)
		{
			this->pointers.push_back(this->value.size());
			for (int j = 0; j < value[i].size(); j++)
			{
				if (value[i][j] != false)
				{
					this->value.push_back(value[i][j]);
					this->cols.push_back(j);
				}
			}
		}
		this->pointers.push_back(this->value.size());
	}
	/*RarefiedMatrix(vector<vector<char>>& value)
	{
		RarefiedMatrix<T>::RarefiedMatrix(vector<vector<char>>& value)
		{
			for (int i = 0; i < value.size(); i++)
			{
				this->pointers.push_back(this->value.size());
				for (int j = 0; j < value[i].size(); j++)
				{
					if (value[i][j] != false)
					{
						this->value.push_back(value[i][j]);
						this->cols.push_back(j);
					}
				}
			}
			this->pointers.push_back(this->value.size());
	}*/
	//RarefiedMatrix(vector<vector<string>>& value);
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
	~RarefiedMatrix()
	{

	}
private:
	vector<T> value;
	vector<int> cols;
	vector<int> pointers;
};

