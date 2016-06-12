package heap;

public class Heap {
	
	int [] heapBox;
	int boxSize;
	int heapSize;
	
	
	public Heap(){
		boxSize=99;
		heapSize=0;
		heapBox=new int[boxSize];
	}
	
	public Heap(int number){
		boxSize=number;
		heapSize=0;
		heapBox=new int[boxSize];
	}
	
	public boolean isEmpty(){
		if (heapBox.length==0){
			return true;
		}
		return false;
	}
	
	public void insert(int number){
		if(heapBox==null){
			heapBox[heapSize]=number;
			heapSize++;
		}else{
		heapBox[heapSize]=number;
		heapifyDown();
		heapSize++;
		}
	}
	
	//swap from top
	public int extractMinTop(){
		

		int top,temp,posParent,posLeftChild,posRightChild;
		//delete top
		top=heapBox[0];
		temp=heapBox[heapSize-1];
		heapBox[heapSize-1]=0;//should be null
		heapBox[0]=temp;
		heapSize--;
		//compare parent with child
		posParent=0;
		posLeftChild=2*posParent+1;
		posRightChild=2*posParent+2;
		
		while(posLeftChild<heapSize && posRightChild<heapSize){

			//pick the smallest child
			
			if(heapBox[posLeftChild]>heapBox[posRightChild]){
				temp=posRightChild;
			}else{
				temp=posLeftChild;
			}
			
			if(heapBox[posParent]>heapBox[temp]){
				swap(posParent,temp);
				posParent=temp;
				posLeftChild=2*posParent+1;
				posRightChild=2*posParent+2;
			}else{
				break;
			}
		}
		
		
		return top;

		
	}
	
	public int extractMaxTop(){

		int top,temp,posParent,posLeftChild,posRightChild;
		//delete top
		top=heapBox[0];
		temp=heapBox[heapSize-1];
		heapBox[heapSize-1]=0;//should be null
		heapBox[0]=temp;
		heapSize--;
		//compare parent with child
		posParent=0;
		posLeftChild=2*posParent+1;
		posRightChild=2*posParent+2;
		
		while(posLeftChild<heapSize && posRightChild<heapSize){

			//pick the largest child
			
			if(heapBox[posLeftChild]>heapBox[posRightChild]){
				temp=posLeftChild;
			}else{
				temp=posRightChild;
			}
			
			if(heapBox[posParent]<heapBox[temp]){
				swap(posParent,temp);
				posParent=temp;
				posLeftChild=2*posParent+1;
				posRightChild=2*posParent+2;
			}else{
				break;
			}
		}
		
		
		return top;
	}
	

	
	//min-heap swap from bottom
	public void heapifyUp(){
		int posParent=(heapSize-1)/2;
		int posChild=heapSize-1;

		while(posChild>0){
		  if(heapBox[posParent]>heapBox[posChild]){
			  //swap
			  swap(posParent,posChild);
			  
		  }
		//update parent and child
		  if(posChild!=0){
			  posChild=posParent;
			  posParent=(posChild-1)/2;
		  }
		}
	}
	//max-heap
	public void heapifyDown(){
		int posParent=(heapSize-1)/2;
		int posChild=heapSize;

		while(posChild!=0){
		  if(heapBox[posParent]<heapBox[posChild]){
			  //swap
			  swap(posParent,posChild);
		  }
		  //update parent and child
		  if(posChild!=0){
			  posChild=posParent;
			  posParent=(posChild-1)/2;
		  }
		}
	}
	
	public void print(){
		for (int i : heapBox) {
			System.out.print(i+" ");
		}
		System.out.println("END Print!");
	}
	
	public void swap(int a,int b){
		int temp;  
		temp=heapBox[a];
		heapBox[a]=heapBox[b];
		heapBox[b]=temp;
	}
	
	public boolean search(int number){
		for (int i : heapBox) {
			if(i==number){
				System.out.println(number+" FOUND!");
				return true;
			}
		}
		System.out.println("NOT FOUND!");
		return false;
	}
}


















