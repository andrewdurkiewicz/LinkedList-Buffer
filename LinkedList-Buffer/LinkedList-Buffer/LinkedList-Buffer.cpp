#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef struct Node {
	string firstName;
	string lastName;
	double gpa;
	Node* next;
};

int main()
{
	string text = "";
	ifstream openfile("Name.txt");
	if (openfile.is_open())
	{
		while(!openfile.eof())
		{
			string nameValue;
			openfile >> nameValue;
			text += nameValue;
		}

	}
	else
	{
	}
	return 0;
}