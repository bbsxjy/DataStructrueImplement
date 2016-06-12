

#include <iostream>

#include <cassert>

#include "stack.h"

using namespace std;


//*************************************************************************


//Representation Invariant:  value >0

//default constructor:
stack::stack(){

    int aBox [2];
}

stack::stack(int arraySpace){
    int aBox [arraySpace];
}



/*
* the push method which indicate the adding data method
* */
void stack::push(int number){
	int size=sizeof(aBox)/sizeof(aBox[0]);
	cout<<size<<endl;
    //loop from the end and update the new array
    for(int i=size-1;i>0;i--){
            aBox[i]=aBox[i-1];  
     }
     aBox[0]=number;
}



    /*
     * the pop method which indicate the deleting data method
     * */
    void stack::pop(){
    	int size=sizeof(aBox)/sizeof(aBox[0]);
        //loop from beginning, move data backwards
        for (int i =0; i<size;i++) {
            if(i+1<size){
            aBox[i]=aBox[i+1];
            }
        }
        aBox[size-1]=0;
    }
    
    /*
     * the peek method which indicate show the last number that entered
     * */
    int stack::peek(){
        return aBox[0];
    }
    
    
    /*
     * the isEmpty method which indicate is this stack empty?
     * */
    bool stack::isEmpty(){
        int counter = 0;
        int size=sizeof(aBox)/sizeof(aBox[0]);
        while(counter!=size){
            if(aBox[counter]==0){
                counter++;
                continue;
            }
            break;
        }
        
        if(counter==size){
            return true;
        }
        return false;
    }
    
    
    
    /*
     * the isFUll method which indicate is the stack full?
     * */
    bool stack::isFull(){
        int counter = 0;
        int size=sizeof(aBox)/sizeof(aBox[0]);
        while(counter!=size){
            if(aBox[counter]!=0){
                counter++;
                continue;
                
            }
            break;
        }
        if(counter==size){
            return true;
        }
        return false;
    }
    
    
    
    /*
     * the print method which indicate printing all the stack
     * */
    void stack::print(){
        int counter=0;
        int size=sizeof(aBox)/sizeof(aBox[0]);
        while(counter!=size){
            cout<<aBox[counter]<<endl;
            counter++;
        }
        cout<<"  "<<endl;
    }
