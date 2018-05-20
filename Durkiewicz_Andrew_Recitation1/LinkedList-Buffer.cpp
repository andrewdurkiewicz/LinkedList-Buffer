//Andrew Durkiewicz HW1 CSE310
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

typedef struct Node
{
	string firstName;
	string lastName;
	double avg;
	Node* next;
} Node;

Node* tmpPtr;
Node* head;
Node* getNext(Node* ptr);

int main()
{
	string text = "";
	ifstream openfile("input.txt");
	string nameValue;
	int count = 0;

	if (openfile.fail())
	{
		cout << "Error opening file, Name.txt does not exist!" << endl;
		exit(1);
	}

	if (openfile.is_open())
	{
		while(!openfile.eof())
		{

			if (count == 0)
			{
				head = new Node();
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
				Node* nextNode = new Node();
				tmpPtr->next = nextNode;
				tmpPtr = nextNode;
				openfile >> nameValue;
				string firstName = nameValue;
				openfile >> nameValue;
				string lastName = nameValue;
				nextNode->firstName = firstName;
				nextNode->lastName = lastName;

			}
			count++;

		}
		openfile.close(); //close the file
	}

	tmpPtr = head;
	while (getNext(tmpPtr) != NULL)
	{
		double enteravg;
		cout << "Please enter the final average for: ";
		cout << tmpPtr->firstName << " " << tmpPtr->lastName << endl << flush;
		cin >> enteravg;
		tmpPtr->avg = enteravg;
		tmpPtr = tmpPtr->next;
	}

	ofstream myfile;
	myfile.open("Output.txt");
	tmpPtr = head;
	while (getNext(tmpPtr) != NULL) //iterate over the linked list
	{
		myfile << tmpPtr->firstName << " " << tmpPtr->lastName << " " << tmpPtr->avg << endl << flush;
		tmpPtr = tmpPtr->next;
	}
	myfile.close();

	return 0;
}

Node* getNext(Node* ptr)
{
	return ptr->next;
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
