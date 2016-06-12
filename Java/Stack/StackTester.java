package Stack;

public class StackTester {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Stack stack=new Stack(6);
		stack.push(9);
		stack.push(8);
		stack.push(7);
		stack.push(6);
		stack.push(5);
		stack.push(4);
		stack.push(3);
		stack.push(2);
		stack.push(1);
		
		System.out.println("Peek is :"+stack.peek());
		stack.print();
		System.out.println("Empty? :"+stack.isEmpty());
		System.out.println("Full? :"+stack.isFull());
		System.out.println("Will do a POP");
		stack.pop();
		stack.pop();
		stack.pop();
		stack.pop();
		stack.pop();
		
		stack.peek();
		System.out.println("Peek is :"+stack.peek());
		stack.print();
		
	}
	
}
