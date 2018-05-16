#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef struct Node{
	string firstName;
	string lastName;
	double gpa;
	Node* next;
};

Node* initNode(string first, string last);
void setNext(Node* thisPtr, Node* nextPtr);

int main()
{
	string text = "";
	ifstream openfile("Name.txt");
	Node* tempPtr;
	Node* head;
	int count = 0;
	if (openfile.is_open())
	{
		while(!openfile.eof())
		{

			string nameValue;
			openfile >> nameValue;
			string firstName = nameValue;
			openfile >> nameValue;
			string lastName = nameValue;
			tempPtr->next = newPtr;
			Node* newPtr = initNode(firstName, lastName);
			tempPtr = newPtr;

			if (count == 0)
			{
				head = newPtr;
				
			}
			tempPtr = newPtr;
			count++;
			system("pause");

		}

	}
	else
	{
	}
	system("pause");
	return 0;
}

Node* initNode(string first, string last)
{
	Node* tmp = new Node();
	tmp->firstName = first;
	tmp->lastName = last;
	return tmp;
}

void setNext(Node* thisPtr, Node* nextPtr)
{
	thisPtr->next = nextPtr;
}
