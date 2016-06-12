// Name: Jingyu Xie
// USC loginid:jingyuxi
// CSCI 455 PA5
// Spring 2016


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
    key=theKey;
    value = theValue;
    next = NULL;
}

Node::Node(const string &theKey,int theValue, Node *n) {
    key=theKey;
    value = theValue;
    next = n;
}




//*************************************************************************
// put the function definitions for your list functions below

//Representation Invariant:  value >0

//default constructor:
listFuncs::listFuncs(){}


//PRE:list is a well-formed list
//insert element at the front of list
void listFuncs::push(ListType &list,const string &theKey, int val){
    list=new Node(theKey,val,list);//create a new node with key & value
                                  //link them to next NULL node
}


//empty the whole list
void listFuncs::clearList(ListType &list){
    ListType rest = list;//create a temporary list
    
    while (list != NULL) {//iterate all list
        rest = list->next;  // rest is all but the first element
        delete list;  // reclaims one node only
        list = rest;
    }
}

// prints list elements, space separated, ending with '\n'
// prints emty list as "<empty>"
void listFuncs::printList(ListType list){
    if (list == NULL) {//if list is NULL print out empty list
        cout << "<empty>"<<endl;
    }
    //create a temporary list
    ListType p = list;
    while (p != NULL) {
        cout <<p->key <<" "<<p->value << " "<<endl;//print out list
        p = p->next;//move to next node
    }
    
}

//remove the single target in the list
//For table calls of remove list element
//return true if found, false otherwise
bool listFuncs::listRemove(ListType &list, string target){
    if(list==NULL){
        cout<<"List is empty"<<endl;
        return false;
    }
    pFirst=list;
    //check whether first node of the list
    ListType preN=NULL;
    ListType delN=NULL;
    
    if (pFirst->key==target)
    {
        delN=pFirst;//make the delN to be to first node
        list=pFirst->next;//list point to the next node of first
        delete delN;//get rid of deln
        return true;
    }
    
    //when it is not the first node
    preN=pFirst;
    delN=pFirst->next;
    //itrating list
    while (delN!=NULL)
    {
        if (delN->key==target)//if found 
        {
            preN->next=delN->next;//make the previous node point to the next of target node
            delete delN;//delete target node
            return true;
        }
        preN=delN;
        delN=delN->next;//otherwise move both pointer to next
    }
    return false;
}

//return the size of the linkedlist
int listFuncs::size(ListType list){
    if(list==NULL){
        cout<<"list is empty"<<endl;
        return 0;
    }
    int counter=0;
    ListType p=list;
    while(p!=NULL){//iterating list
        p=p->next;
        counter++;//counting elements
    }
    return counter;
}



//lookup certain target and return true if found
//false if not found
bool listFuncs::listLookup(ListType list, string target){
    if(list==NULL){
        cout<<"list is empty"<<endl;//if empty list retrun false
        return false;
    }
    ListType p=list;
    while(p!=NULL){
        if(p->key==target){//if target found return true
            return true;
        }
        p=p->next;//otherwise move to next node
    }
    return false;//not found
}

//getter function,return the address of the certain target
//if not found return NULL
int* listFuncs::getValue(ListType list,string target){
    if(listLookup(list,target)==true){//if found target
        ListType p=list;
        while(p!=NULL){//iterating
            if(p->key==target){
                return &p->value;//return the address of target value
            }
            p=p->next;
        }
    }else{
        return NULL;//if not found 
    }
}