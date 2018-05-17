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

int main()
{
	string text = "";
	ifstream openfile("Name.txt");
	Node* head = new Node();
	string nameValue;

	int count = 0;
	if (openfile.is_open())
	{
		while(!openfile.eof())
		{
			Node* tmpPtr = new Node();

			if (count == 0)
			{
				tmpPtr = head;
				openfile >> nameValue;
				string firstName = nameValue;
				openfile >> nameValue;
				string lastName = nameValue;
				head->firstName = firstName;
				head->lastName = lastName;
			}

			else
			{
				Node* newNode = new Node();
				*tmpPtr->next = newNode;
				tmpPtr = newNode;
				openfile >> nameValue;
				string firstName = nameValue;
				openfile >> nameValue;
				string lastName = nameValue;
				newNode->firstName = firstName;
				newNode->lastName = lastName;

			}
			count++;
			
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
