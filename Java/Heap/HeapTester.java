package heap;

public class HeapTester {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Heap heap=new Heap(15);
		heap.insert(9);
		heap.print();
		heap.insert(10);
		heap.print();
		heap.heapifyUp();
		heap.insert(11);
		heap.print();
		heap.insert(6);
		heap.print();
		heap.insert(12);
		heap.print();
		heap.insert(5);
		heap.print();
		heap.insert(3);
		heap.print();
		heap.insert(13);
		heap.print();
		heap.insert(14);
		heap.print();
		heap.insert(15);
		heap.print();
		heap.insert(2);
		heap.print();
		heap.insert(1);
		heap.print();
		heap.insert(16);
		heap.print();
		heap.insert(17);
		heap.print();
		heap.extractMaxTop();
		heap.print();
		
		
		heap.search(5);
		heap.search(99);
//		heap.insert(18);
//		heap.print();
		int i=0;
		while(i<10){
			System.out.println("you are now extracting: "+heap.extractMaxTop());
			heap.print();
			i++;
		}
	}

}
