/*****************************************
* Shahrood User ID:  -
* Submitted for Data Structure Course
* Department of Computer Engineering and IT
* Shahrood University of Technology
*
* By submitting this file, I affirm that
* I am the author of all modifications to
* the provided code.
*****************************************/

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>
#include "exception.h"

class DoubleLinkedList {
public:
	class DoubleNode {
	public:
		DoubleNode(int const& = int(), DoubleNode* = nullptr, DoubleNode* = nullptr);

		int value() const;
		DoubleNode* previous() const;
		DoubleNode* next() const;
		void setnext(DoubleNode*);

		int         nodeValue;
		DoubleNode* previousNode;
		DoubleNode* nextNode;
	};

	DoubleLinkedList();
	DoubleLinkedList(DoubleLinkedList const&);
	~DoubleLinkedList();

	// Accessors

	int size() const;
	bool empty() const;

	int front() const;
	int back() const;

	DoubleNode* begin() const;
	DoubleNode* end() const;

	DoubleNode* find(int const&) const;
	int count(int const&) const;

	// Mutators

	void swap(DoubleLinkedList&);

	void pushFront(int const&);
	void pushBack(int const&);

	void popFront();
	void popBack();

	int erase(int const&);

private:
	DoubleNode* listHead;
	DoubleNode* listTail;
	DoubleNode* newnode;
	DoubleNode* node;
	int listSize;

	// List any additional private member functions you author here
	// Friends

	friend std::ostream& operator<<(std::ostream&, DoubleLinkedList const&);
};

/////////////////////////////////////////////////////////////////////////
//                      Public member functions                        //
/////////////////////////////////////////////////////////////////////////


/*This function is the constructor and sets the default values ​​for it*/
DoubleLinkedList::DoubleLinkedList() :
	// Updated the initialization list here
	listHead(nullptr),
	listTail(nullptr),
	listSize(0)
{
	// Enter your implementation here
}


/*this function is copy constructor give a input of the type doublelinklist and with a loop
pushback To the current list*/
DoubleLinkedList::DoubleLinkedList(DoubleLinkedList const& list) :
	// Updated the initialization list here
	listHead(nullptr),
	listTail(nullptr),
	listSize(0)
{
	// Enter your implementation here
	for (DoubleNode* ptr = list.begin(); ptr != nullptr; ptr = ptr->next()) {
		this->pushBack(ptr->value());
	}


}



DoubleLinkedList::~DoubleLinkedList() {
	// Enter your implementation here
}


/*this function return listsize*/
int DoubleLinkedList::size() const {
	return listSize;
}


/*this function chcked list is empty or not if empty return true else return false*/
bool DoubleLinkedList::empty() const {
	return begin() == nullptr;
}


/*this function is point to headlist if listhead is null trow exteption else return listhead value*/
int DoubleLinkedList::front() const {
	if (begin() == nullptr) {
		throw Underflow();
	}

	return begin()->value(); // This returns the default value
}


/*this function is point to taillist if listtail is null trow exteption else return listtail value*/
int DoubleLinkedList::back() const {
	if (end() == nullptr) {
		throw Underflow();
	}

	return end()->value(); // This returns the default value
}


/*this function is return listhead*/
DoubleLinkedList::DoubleNode* DoubleLinkedList::begin() const {
	// Enter your implementation here

	return listHead;
}


/*this function is return listtail*/
DoubleLinkedList::DoubleNode* DoubleLinkedList::end() const {
	// Enter your implementation here

	return listTail;
}


/*this function is give a input of the type int and with a loop
checked it if (value == nodevalue) return nodeaddress else return null*/
DoubleLinkedList::DoubleNode* DoubleLinkedList::find(int const& value) const {
	for (auto ptr = this->begin(); ptr != nullptr; ptr = ptr->next()) {
		if (ptr->nodeValue == value) {
			return ptr;
		}
	}
	return nullptr;
}


/*this function is give a input of the type int and with a loop
checked it. if (value == nodevalue)increase size and finally return size*/
int DoubleLinkedList::count(int const& value) const {
	DoubleNode* node = listHead;
	int size = 0;
	while (node != nullptr)
	{
		if (node->nodeValue == value) {
			size++;
		}
		node = node->next();
	}
	delete node;
	return size;
}


/*this function is give a input of the type doublelinklist
and moves it with the current object*/
void DoubleLinkedList::swap(DoubleLinkedList& list) {
	DoubleNode* temp1 = this->listHead;
	this->listHead = list.listHead;
	list.listHead = temp1;

	DoubleNode* temp2 = this->listTail;
	this->listTail = list.listTail;
	list.listTail = temp2;

	int length = this->listSize;
	this->listSize = list.listSize;
	list.listSize = length;
}


/*this function is give a input of the type int
and check list. if list is empty sets listhead and listtail with it
else pushfront To the bottom of the list*/
void DoubleLinkedList::pushFront(int const& value) {
	if (!empty()) {
		listHead = new DoubleNode(value, nullptr, begin());
		(listHead->nextNode)->previousNode = listHead;
	}
	if (empty()) {
		listHead = new DoubleNode(value, nullptr, nullptr);
		listTail = listHead;
	}
	listSize++;
}


/*this function is give a input of the type int
and check list. if list is empty sets listhead and listtail with it
else pushback To the top of the list*/
void DoubleLinkedList::pushBack(int const& value) {
	if (!empty())
	{
		listTail = new DoubleNode(value, listTail, nullptr);
		(listTail->previousNode)->nextNode = listTail;
	}
	if (empty()) {
		pushFront(value);
		return;
	}
	listSize++;
}


/*this function just delete From the beginning of the list
if list is empty trow exteption  else if not empty but have one node
listhead and listtail is sets null else delete The first node*/
void DoubleLinkedList::popFront() {
	if (empty()) {
		throw Underflow();
	}
	if (!empty() && listSize == 1) {
		listHead = nullptr;
		listTail = nullptr;
	}
	if (!empty()) {
		listHead = listHead->next();
		listHead->previousNode = nullptr;
	}
	listSize--;
}


/*this function just delete From the bottom of the list
if list is empty trow exteption  else if not empty but have one node
listhead and listtail is sets null else delete The last node*/
void DoubleLinkedList::popBack() {
	if (empty()) {
		throw Underflow();
	}
	if (!empty() && listSize == 1) {
		listHead = nullptr;
		listTail = nullptr;
	}
	if (!empty()) {
		listTail = listTail->previous();
		listTail->nextNode = nullptr;
	}
	listSize--;
}


/*this function erase node that equal with input
In this way if (nodevalue ==input) if node is equal listhead*/
int DoubleLinkedList::erase(int const& value) {
	DoubleNode* node = listHead;
	int size = 0;
	while (node != nullptr)
	{
		if (node->nodeValue == value) {
			if (node != listHead && node != listTail) {
				((node->previousNode)->nextNode) = (node->nextNode);
				newnode = node->nextNode;
				DoubleNode* n = (node->previousNode);
				delete node;
				node = newnode;
				(node->previousNode) = n;
				size++;
				listSize--;
				continue;
			}
			if (node == listHead) {
				newnode = node->nextNode;
				delete node;
				node = newnode;
				node->previousNode = nullptr;
				listHead = node;
				size++;
				listSize--;
				continue;
			}
			if (node == listTail) {
				((node->previousNode)->nextNode) = nullptr;
				listTail = node->previousNode;
				listTail->nextNode = nullptr;
				delete node;
				node = nullptr;
				size++;
				listSize--;
				continue;
			}
		}
		node = node->next();
	}
	return size;
}


/*this is constructor from dublenode
Places input values ​​in defined values*/
DoubleLinkedList::DoubleNode::DoubleNode(
	int const& nv,
	DoubleLinkedList::DoubleNode* pn,
	DoubleLinkedList::DoubleNode* nn) :
	// Updated the initialization list here
	nodeValue(nv), // This assigns 'nodeValue' the default value
	previousNode(pn),
	nextNode(nn)
{
	// Enter your implementation here

}


/*this function just return nodevalue*/
int DoubleLinkedList::DoubleNode::value() const {
	// Enter your implementation here

	return nodeValue; // This returns the default value
}


/*this function just return previousnode*/
DoubleLinkedList::DoubleNode* DoubleLinkedList::DoubleNode::previous() const {
	// Enter your implementation here

	return previousNode;
}


/*this function just return nextnode*/
DoubleLinkedList::DoubleNode* DoubleLinkedList::DoubleNode::next() const {
	// Enter your implementation here

	return nextNode;
}


/*this function just set nextnode with input*/
void DoubleLinkedList::DoubleNode::setnext(DoubleNode* n) {
	nextNode = n;
}

/////////////////////////////////////////////////////////////////////////
//                      Private member functions                       //
/////////////////////////////////////////////////////////////////////////

// If you author any additional private member functions, include them here

/////////////////////////////////////////////////////////////////////////
//                               Friends                               //
/////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& out, DoubleLinkedList const& list) {
	out << "head";

	// print list from start to end
	for (auto* ptr = list.begin(); ptr != nullptr; ptr = ptr->next()) {
		out << "->" << ptr->value();
	}
	out << "->0" << std::endl << "tail";

	// print list from end to start
	for (auto ptr = list.end(); ptr != nullptr; ptr = ptr->previous()) {
		out << "->" << ptr->value();
	}
	out << "->0";

	return out;
}

#endif
