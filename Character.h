#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


class Character
{
public:
	Character(string filename, int id);
	int getId();
	string& getName();
	int getBooksNumber();
	vector<string>& getBookNames();
	vector<string>& getStatus();
	void print();
	static int sizeofCharactersFile();
	~Character();
private:
	int id;
	string name;
	int booksNumber;
	vector<string> booknames;
	vector<string> status;
};
