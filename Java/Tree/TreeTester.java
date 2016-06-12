package tree;

public class TreeTester {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Tree t=new Tree();
		
		t.insert(5);
		t.insert(4);
		t.insert(8);
		t.insert(3);
		t.insert(2);
		t.insert(1);
		t.insert(7);
		t.insert(9);
		t.insert(10);
		
		System.out.println(t.countNodes());
		t.delete(2);
		System.out.println(t.countNodes());
		

	}

}
