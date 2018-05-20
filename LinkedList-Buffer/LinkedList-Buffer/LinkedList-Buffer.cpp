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
Node* tmpPtr;
Node* head;
Node* getNext(Node* ptr);

int main()
{
	string text = "";
	ifstream openfile("Name.txt");

	string nameValue;

	int count = 0;
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

	}
	else
	{
	}
	Node* tmp = head;
	while (getNext(tmp) != NULL)
	{
		double enterGPA;
		cout << "Please enter the GPA for: ";
		cout << tmp->firstName << " " << tmp->lastName << endl << flush;
		cin >> enterGPA;
		tmp->gpa = enterGPA;
		tmp = tmp->next;
	}
	tmp = head;
	while (getNext(tmp) != NULL)
	{
		cout << tmp->firstName << " " << tmp->lastName << " has a GPA of: " << tmp->gpa << endl << flush;
		tmp = tmp->next;
	}
	
	system("pause");
	return 0;
}
Node* getNext(Node* ptr) {
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
