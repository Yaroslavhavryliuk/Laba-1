#include "Header.h"
#include "Source.cpp"



int main()
{
	string**value = new string * [5];
	for (int i = 0; i < 5; i++)
	{
		value[i] = new string[5];
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			value[i][j] = "Naruto";
		}
	}
	Matrix<string> matr(value, 5, 5);
	int rd = matr.getRd();
	int st = matr.getSt();
	string** arr = new string* [rd];
	for (int i = 0; i < rd; i++)
	{
		arr[i] = new string[st];
    }
	arr = matr.getValues();
	for (int i = 0; i < rd; i++)
	{
		for (int j = 0; j < st; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}

