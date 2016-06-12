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

#include "stack.h"


int main() {
	stack g (11);
	

	cout<<"insert value 1"<<endl;
	g.push(1);

	cout<<"insert value 2"<<endl;
	g.push(2);
	
	cout<<"insert value 3"<<endl;
	g.push(3);
	
	cout<<"insert value 4"<<endl;
	g.push(4);

	cout<<"insert value 5"<<endl;
	g.push(5);

	cout<<"insert value 6"<<endl;
	g.push(6);

	cout<<"insert value 7"<<endl;
	g.push(7);

	cout<<"insert value 8"<<endl;
	g.push(8);

	cout<<"insert value 9"<<endl;
	g.push(9);

	
	
	cout<<"going to print out the stack value"<<endl;
	g.print();
	
		
	cout<<"removing first value in stack"<<endl;
	g.pop();
	g.print();
	

	cout<<"Peek is : "<<g.peek()<<endl;


	cout<<"Empty? "<<g.isEmpty()<<endl;
	cout<<"Full? "<<g.isFull()<<endl;


	

  return 0;
}
