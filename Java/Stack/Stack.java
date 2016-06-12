package Stack;



public class Stack {
	private int arraySpace;
	private int[] aBox; 
	
	/**
	 * the implementation of stack using JAVA array
	 * empty constructor with a default space for stack :2
	 * */
	public Stack(){
		arraySpace=2;
		aBox=new int[arraySpace];
	}
	/**
	 *  With user given space for stack
	 * */
	public Stack(int arraySpace){
		this.arraySpace=arraySpace;
		aBox=new int[arraySpace];
	}
	
	/*
	 * the push method which indicate the adding data method
	 * */
	public void push(int number){
		//loop from the end and update the new array
		for(int i=aBox.length-1;i>0;i--){
				aBox[i]=aBox[i-1];	
		}
		aBox[0]=number;
	}
	
	/*
	 * the pop method which indicate the deleting data method
	 * */
	public void pop(){
		//loop from beginning, move data backwards
		for (int i =0; i<aBox.length;i++) {
			if(i+1<aBox.length){
			aBox[i]=aBox[i+1];
			}
		}
		aBox[aBox.length-1]=0;
	}
	
	/*
	 * the peek method which indicate show the last number that entered
	 * */
	public int peek(){
		return aBox[0];
	}
	
	
	/*
	 * the isEmpty method which indicate is this stack empty?
	 * */
	public boolean isEmpty(){
		int counter = 0;
		while(counter!=aBox.length){
			if(aBox[counter]==0){
				counter++;
				continue;
			}
			break;
		}
		
		if(counter==aBox.length){
			return true;
		}
		return false;
	}
	
	
	
	/*
	 * the isFUll method which indicate is the stack full?
	 * */
	public boolean isFull(){
		int counter = 0;
		while(counter!=aBox.length){
			if(aBox[counter]!=0){
				counter++;
				continue;
				
			}
			break;
		}
		if(counter==aBox.length){
			return true;
		}
		return false;
	}
	
	
	
	/*
	 * the print method which indicate printing all the stack
	 * */
	public void print(){
		int counter=0;
		while(counter!=aBox.length){
			System.out.print(aBox[counter]);
			counter++;
		}
		System.out.println();
	}
}
