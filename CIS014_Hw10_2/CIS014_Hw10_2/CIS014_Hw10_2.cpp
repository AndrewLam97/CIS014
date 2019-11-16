#include <iostream>
using namespace std;

class Node {
public:
	int value;  //payload
	Node* next; //pointer to next node
	Node(int v) : value(v), next(nullptr) {} //constructor
};

class CIS14 {
public:
	Node* getClosestCommonWaypoint(Node* A, Node* B);
};

Node* CIS14::getClosestCommonWaypoint(Node* A, Node* B)
{
	Node* tmp = A;
	Node* tmp1 = B;
	while (tmp->next != nullptr)
	{
		while (tmp1->next != nullptr)
		{

			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}

int main()
{
	CIS14 cis14;

	Node a(10), a1(11), a2(12), a3(13), a4(14), b1(21), b2(22), c1(31), c2(32);
	a.next = &a1; a1.next = &a2; a2.next = &a3; a3.next = &a4; a4.next = &c1;
	b1.next = &b2; b2.next = &c1;
	c1.next = &c2;

	cout << (&c1 == cis14.getClosestCommonWaypoint(&a, &b1));
}
