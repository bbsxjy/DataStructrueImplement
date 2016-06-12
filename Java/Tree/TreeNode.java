package tree;

/**
 * This is the <Integer> node class can be used to
 *  implement various tree with the data type of Integer 
 *  
 *  Jingyu xie
 *  2016/6/4
 * */

public class TreeNode {
	//given overall data name
	private TreeNode left, right;
	private int data;
	
	//empty constructor
	public TreeNode(){
		left=null;
		right=null;
		data=0;
	}
	
	//with given number constructor
	public TreeNode(int n){
		left=null;
		right=null;
		data=n;
	}
	
	
	//setter function of left/right node
	public void setLeft(TreeNode n){
		left=n;
	}
	public void setRight(TreeNode n){
		right=n;
	}
	
	//getter function of left/right node
	public TreeNode getLeft(){
		return left;
	}
	public TreeNode getRight(){
		return right;
	}
	
	//setter function of data
	public void setData(int d){
		data=d;
	}
	
	//getter function of data
	public int getData(){
		return data;
	}
	
	public void printNode(TreeNode n){
		System.out.print(n.getLeft().getData()+"  ");
		System.out.print(n.getRight().getData());
		System.out.println();
	}
	
	
}
