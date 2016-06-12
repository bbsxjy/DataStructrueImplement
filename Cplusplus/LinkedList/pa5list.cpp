// Name:Jingyu Xie
// loginid:jingyuxi
// CS 455 Lab 13 / PA5

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile (and lab 13 Makefile) includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"


int main() {
	listFuncs g;
	ListType thelist = NULL;
	//cout<<"going to start building list";
	//newList(thelist);

	cout<<"insert value 1"<<endl;
	g.push(thelist,"a",1);

	cout<<"insert value 2"<<endl;
	g.push(thelist,"b",2);
	
	cout<<"insert value 3"<<endl;
	g.push(thelist,"c",3);
	
	cout<<"insert value 4"<<endl;
	g.push(thelist,"e",4);

		cout<<"insert value 4"<<endl;
	g.push(thelist,"f",4);

		cout<<"insert value 4"<<endl;
	g.push(thelist,"g",4);

		cout<<"insert value 4"<<endl;
	g.push(thelist,"h",4);


		cout<<"insert value 4"<<endl;
	g.push(thelist,"i",4);


		cout<<"insert value 4"<<endl;
	g.push(thelist,"p",4);

	
	
	cout<<"going to print out the list value"<<endl;
	g.printList(thelist);
	
	cout<<"going to output the size of list"<<endl;
	cout<<"Result: "<<g.size(thelist)<<endl;

		
	cout<<"removing the existed value in list"<<endl;
	g.listRemove(thelist,"p");
	g.printList(thelist);
	cout<<"Size: "<<g.size(thelist)<<endl;

	cout<<"removing the existed value in list"<<endl;
	g.listRemove(thelist,"f");
	g.printList(thelist);
	cout<<"Size: "<<g.size(thelist)<<endl;

		cout<<"removing the existed value in list"<<endl;
	g.listRemove(thelist,"g");
	g.printList(thelist);
	cout<<"Size: "<<g.size(thelist)<<endl;

		cout<<"removing the existed value in list"<<endl;
	g.listRemove(thelist,"h");
	g.printList(thelist);
	cout<<"Size: "<<g.size(thelist)<<endl;


		cout<<"removing the existed value in list"<<endl;
	g.listRemove(thelist,"i");
	g.printList(thelist);
	cout<<"Size: "<<g.size(thelist)<<endl;

		cout<<"removing the existed value in list"<<endl;
	g.listRemove(thelist,"b");
	g.printList(thelist);
	cout<<"Size: "<<g.size(thelist)<<endl;
	

  return 0;
}
