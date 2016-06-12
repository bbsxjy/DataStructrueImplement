// Name: Jingyu Xie
// USC loginid:jingyuxi
// CSCI 455 PA5
// Spring 2016

// Table.cpp  Table class implementation


/*
* Modified 11/22/11 by CMB
*   changed name of constructor formal parameter to match .h file
*/

#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"

//*************************************************************************

//Representation Invariant: 1* size of hashsize is at least 1
//                          2* value >0


// create an empty table, i.e., one where numEntries() is 0
// (Underlying hash table is HASH_SIZE.)
Table::Table() {
    hashSize=HASH_SIZE;
    array=new ListType[hashSize];//open size of hashSize array

    for(int i=0;i<hashSize;i++){
        array[i]=NULL;//initialize array
    }

}

// create an empty table, i.e., one where numEntries() is 0
// such that the underlying hash table is hSize
Table::Table(unsigned int hSize) {
    hashSize=hSize;
    array=new ListType[hashSize];//open size of hashSize array

    for(int i=0;i<hashSize;i++){
        array[i]=NULL;//initialize array
    }

}

// returns the address of the value or NULL if key is not present
int * Table::lookup(const string &key) {

    listFuncs link;//new instance of listFuncs
    int index=hashCode(key);//get the index after through hashed function
    
    if(array[index]!=NULL){//if array is not empty
        if(link.getValue(array[index],key)==NULL){//if no value returned
            return NULL;
        }
        return link.getValue(array[index],key);//return address
    }
    return NULL;   // target not found
}

// remove an element
// false iff element wasn't present
bool Table::remove(const string &key) {
    listFuncs link;
    int index=hashCode(key);
    if(array[index]!=NULL && link.listLookup(array[index],key)==true){//if array not empty and there is an entry
        link.listRemove(array[index],key);//get the target removed
        
        return true;
    }
    
    return false;  // not found target
}

// insert a new pair into the table
// return false iff this key was already present 
//         (and no change made to table)
bool Table::insert(const string &key, int value) {
    listFuncs link;
    int index=hashCode(key);
    
    if(lookup(key)==NULL){//if there no this key present yet
        link.push(array[index],key, value);//insert this new entry
        
        return true;
    }
    
    return false;  // theres already key presented in the table
}

// number of entries in the table
int Table::numEntries() const {
    listFuncs link;
    int counter=0;
    for (int i = 0; i < hashSize; ++i)
    {
        if(array[i]!=NULL){
            counter=counter+link.size(array[i]);//continue addup till get the total number
        }
    }
    return counter;      // return results
}

// print out all the entries in the table, one per line.
// Sample output:
//   joe 32
//   sam 273
//   bob 84
void Table::printAll() const {
    listFuncs link;
    for (int i = 0; i < hashSize; i++)
    {
        if(array[i]!=NULL){
            link.printList(array[i]);//print out the list of each entry
        }
    }
}

//   number of buckets: 997
//   number of entries: 10
//   number of non-empty buckets: 9
//   longest chain: 2
void Table::hashStats(ostream &out) const {
    listFuncs link;
    int nonEmpty=0;//counter of non-empty buckets
    int largest=0;//counter of the chain length counter
    for (int i = 0; i < hashSize; ++i)
    {
        if(array[i]!=NULL){//if not empty
            if(link.size(array[i])>largest){//compare the chain length
                largest=link.size(array[i]);//if longer make it to be the longest
            }
            nonEmpty++;
        }
    }
    out<<"number of buckets: "<<hashSize<<endl;
    out<<"number of entries: "<<numEntries()<<endl;
    out<<"number of non-empty buckets: "<<nonEmpty<<endl;
    out<<"longest chain: "<<largest<<endl;
    
}


// add definitions for your private methods here