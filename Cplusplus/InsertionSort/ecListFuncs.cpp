/*  Name:Jingyu Xie
 *  loginid:jingyuxi
 *  CS 455 Spring 2016, Extra Credit assignment
 *
 *  See ecListFuncs.h for specification of each function.
 */

#include <iostream>

#include <cassert>

#include "ecListFuncs.h"

 using namespace std;


 bool isInOrder(ListType list) {
	//empty list
 	if (list==NULL){
 		return true;
 	}

	//while only one element
 	if (list->next==NULL)
 	{
 		return true;
 	}
	//other situation
 	else
 	{
 		ListType p =list;
 		//begin iterating
 		while(p!=NULL){
 			int prev=p->data;
 			p=p->next;
 			if (p==NULL)
 			{
 				return true;
 			}
 			int curn=p->data;	
 			//if first many are in order continue otherwise return false
 			if (curn>prev || curn==prev)
 			{
 				continue;
 			}else{
 				return false;
 			}


 		}


 	}
 }



 void insertInOrder(ListType & list, Node *itemP) {
  assert(isInOrder(list));     // checks the preconditions
  assert(itemP->next == NULL);
  // add the rest of the code after this line
  ListType p=list;
  ListType prev=NULL;

  //NULL case
  if (list==NULL)
  {
  	list=itemP;
  	list->next=NULL;
  	
  }else{

  	while(p!=NULL){
  	//if the itemP bigger than the first many nodes
  		if((itemP->data>p->data) ||(itemP->data==p->data)){
  			prev=p;
  			p=p->next;
  			if (p==NULL)
  			{
  				prev->next=itemP;
  				break;
  			}
  			continue;
  		}else{
  		//smaller than first node
  			if(prev==NULL){
  				itemP->next=list;
  				list=itemP;
  				break;
  			}
  		//otherwise
  			prev->next=itemP;
  			itemP->next=p;
  			break;
  		}
  	}

  }

}



void insertionSort(ListType &list) {
	ListType p=list;
	ListType prev=NULL;//the list point to that before current
	ListType curn=NULL;//the list currently point to
	ListType temp=NULL;//save the temparary node
	ListType tempL=NULL;//save the list after temparary node
	ListType preTemp=NULL;//the first many in ordered nodes
	bool isDone=isInOrder(p);


	while(isDone==false){

		if (isInOrder(list)==true)
		{
			isDone=true;
		}

		else
		{
			prev=p;
			curn=p->next;	

  		//if the next data<previouse data then swap

			while(curn!=NULL){


				if(curn->data<prev->data)
				{

  			//break the link to 3 parts
  			//temp:the node need to be sorted
					temp=curn;
  			//tempL:the list after temp
					tempL=curn->next;
  			//isolate temp make it to be a node
					temp->next=NULL;
  			//the list before temp
					prev->next=NULL;

  			//insert sorting the temp node with the first n sorted list
					insertInOrder(list,temp);
  			//setup an list iterator
					preTemp=list;
					while(preTemp->next!=NULL){
						preTemp=preTemp->next;
					}
  			//link the first n+1 list into the list after temp
					preTemp->next=tempL;
  			//re-assgin the previous and current pointer into the new list
					prev=list;
					curn=list->next;	

				}
  		//if the first many is in order,move pointer
				else
				{	

					prev=curn;
					curn=curn->next;

				}

			}

		}
	}

}


void splitEvenOdd(ListType &list, ListType &a, ListType &b){

	

	//NULL case
	if(list==NULL){
		a=NULL;
		b=NULL;
		return;
	}

	a=list;
	b=list->next;
	ListType p=list;
	ListType tempA=a;//odd case temp
	ListType tempB=b;//even case temp
	bool isDone=false;
	
	//if there is only 1 element
	if (list->next==NULL)
	{
		a=list;
		b=NULL;
		isDone=true;
		list=NULL;
	}
	//while isdone false
	else if(isDone==false){
		//iterate the even # temp
		while(tempB!=NULL){

			//point to the even #'s next'
			tempA->next=tempB->next;
			//while even# has next
			if(tempB->next!=NULL){
				tempB->next=tempB->next->next;//assgin its next to the next of next
			}
			//move pointer
			tempA=tempA->next;
			tempB=tempB->next;


		}
		list=NULL;
		isDone=true;
	}
}
