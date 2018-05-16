#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef struct{
	string firstName;
	string lastName;
	double gpa;
	Node* next = NULL;
}Node;

Node* initNode(string first, string last);
void setNext(Node* thisPtr, Node* nextPtr);

int main()
{
	string text = "";
	ifstream openfile("Name.txt");
	static int count = 0;
	if (openfile.is_open())
	{
		while(!openfile.eof())
		{

			string nameValue;
			openfile >> nameValue;
			string firstName = nameValue;
			string lastName = nameValue;
			Node* lastPtr = initNode(firstName, lastName);
			count++;

			
		}

	}
	else
	{
	}
	return 0;
}

Node* initNode(string first, string last)
{
	Node* tmp = new Node();
	tmp->firstName = first;
	tmp->lastName = last;
	tmp->next = NULL;
	return tmp;
}

void setNext(Node* thisPtr, Node* nextPtr)
{
	thisPtr->next = nextPtr;
}
