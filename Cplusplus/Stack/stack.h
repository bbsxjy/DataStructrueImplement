


//*************************************************************************
// Stack class definition with array implementation




using namespace std;



//*************************************************************************
//with all the function methods


class stack{
public:
	
	int aBox [];

	//default constructor:
	stack();
	//with given number constructor:
	stack(int arraySpace);


	//PRE:array is initialized
	//adding the number into the stack
	void push(int number); 

	//PRE:array is initialized
	//poping out the number of the stack
	void pop();

	//PRE:array is initialized
	//the last element that pushed into the stack
	int peek();

	//tell whether the stack is empty
	bool isEmpty();

	//tell whether the stack is full
	bool isFull();

	//print all the stack
	void print();


};












