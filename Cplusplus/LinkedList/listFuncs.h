// Name: Jingyu Xie
// USC loginid:jingyuxi
// CSCI 455 PA5
// Spring 2016


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// used by the Table class; not by any Table client code.


#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

using namespace std;

struct Node {
	string key;
	int value;

	Node *next;

	Node(const string &theKey, int theValue);

	Node(const string &theKey,int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.
class listFuncs{
public:
	//default constructor:
	listFuncs();

	//first node of the list
	Node *pFirst;

	//PRE:list is a well-formed list
	//insert element at the front of list
	void push(ListType &list,const string &theKey, int val);

	//make list into an empty list
	void clearList(ListType &list);

	// prints list elements, space separated, ending with '\n'
	// prints emty list as "<empty>"
	void printList(ListType list);

	//For table calls of remove list element
	//return true if found, false otherwise
	bool listRemove(ListType &list, string target);

	//return the size of the list
	int size(ListType list);

	//lookup certain target and return true if found
	//false if not found
	bool listLookup(ListType list, string target);

	//getter function,return the address of the certain target
	//if not found return NULL
	int* getValue(ListType list,string target);


};












// keep the following line at the end of the file
#endif
