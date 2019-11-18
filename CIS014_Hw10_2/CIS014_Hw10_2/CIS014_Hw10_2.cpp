/*
ASSIGNMENT: 10.2
DUE: 11/17/19
PURPOSE: Outputs the closest common waypoint from any given two path input, Node* A, and Node* B
*/
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

/*
PURPOSE: Outputs the closest common waypoint from any given two path input, Node* A, and Node* B
PARAMETERS: Node pointer A and B containing a path in the form a linked list
RETURN VALUES: Node pointer of closest common waypoint
*/
Node* CIS14::getClosestCommonWaypoint(Node* A, Node* B)
{
	Node* tmp = A;
	Node* tmp1 = B;

	if (A == nullptr || B == nullptr) //check if inputs are nullptrs
	{
		return nullptr;
	}

	while (tmp != nullptr) //while not at end of path
	{
		while (tmp1 != nullptr) //while not at end of other path
		{
			if (tmp == tmp1) //check equivalence
			{
				return tmp;
			}
			tmp1 = tmp1->next; //iterate pointer by setting current pointer to next
		}
		tmp1 = B; //reset inner loop
		tmp = tmp->next; //iterate outer loop's pointer
	}
	return nullptr;
}

int main()
{
	CIS14 cis14;

	Node  a1(11), a2(12), a3(13), b1(21), b2(22), c1(31), c2(32), d1(99);
	a1.next = &a2; a2.next = &a3; a3.next = &b1;
	b1.next = &b2; b2.next = &c1;
	c1.next = &c2;
	
	cout << (&b1 == cis14.getClosestCommonWaypoint(&a1, &b1));
}

/*
TEST CASES:
	Node  a1(11), a2(12), a3(13), b1(21), b2(22), c1(31), c2(32), d1(99);
	a1.next = &a2; a2.next = &a3; a3.next = &c1;
	b1.next = &b2; b2.next = &c1;
	c1.next = &c2;

	cout << (&c1 == cis14.getClosestCommonWaypoint(&a1, &c1));	1

	Node  a1(11), a2(12), a3(13), b1(21), b2(22), c1(31), c2(32), d1(99);
	a1.next = &a2; a2.next = &a3; a3.next = &c1;
	b1.next = &b2; b2.next = &c1;
	c1.next = &c2;

	cout << (nullptr == cis14.getClosestCommonWaypoint(nullptr, &c1));	1

	Node  a1(11), a2(12), a3(13), b1(21), b2(22), c1(31), c2(32), d1(99);
	a1.next = &a2; a2.next = &a3; a3.next = &b1;
	b1.next = &b2; b2.next = &c1;
	c1.next = &c2;

	cout << (&b1 == cis14.getClosestCommonWaypoint(&a1, &b1));	1


*/