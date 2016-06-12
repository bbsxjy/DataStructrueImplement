
/**
 * This is the Binary Tree implement class with TreeNode
 *  
 *  Jingyu xie
 *  2016/6/4
 * */

public class Tree {
	private TreeNode root;

	
	//constructor
	public Tree(){
		root=null;
	}
	
	//check the tree is empty or not
	public boolean isEmpty(){
		if(root==null){
		System.out.println("Empty");
		return true;
		}
		return false;
		
	}
	
	//insert data into tree
	public void insert(int data){
		if(isEmpty()==true){
			root=new TreeNode(data);
			System.out.println("Insert at root Success!!");
			return;
		}
		insert(root,data);
	}
	//the helper function
	private boolean insert(TreeNode node,int data){
		//determine whether the next node of the given node is empty or not
		//if they are not empty then proceed
			//if the entered data is smaller than the given node
			//,then save it to the left of the given node
			//otherwise, use right to save
		if(data==node.getData()){
			System.out.println("You have inserted a duplicated data!! Please double check!");
			return false;
		}
		else if(data<node.getData()){
			//if left is not empty, then proceed the insert recursively
			if(node.getLeft()!=null){
			return insert(node.getLeft(),data);
			}
			//otherwise proceed the insert directly
			node.setLeft(new TreeNode(data));
		}else{
			//if right is not empty, then proceed the insert recursively
			if(node.getRight()!=null){
			return insert(node.getRight(),data);
			}
			//otherwise proceed the insert directly
			node.setRight(new TreeNode(data));
		
		}
		System.out.println("Insert Success!!");
		return true;
	}
	
    
    /* Functions to delete data */
    /**
     * This basic function idea is same as the linkedlist node:
     * if you want to delete one node from the tree,just simply link the parent node to the 
     * on-deleting node's child node which indicate the techniques: voiding
     * 
     * */
    public void delete(int k)
    {
        if (isEmpty()) {
            System.out.println("Tree is empty!");
        }else if (search(k)==false) {
            System.out.println("Value not found!");
        }else{
            //if the number=root.data,delete root and the root should change
            root=delete(root,k);
        }
    }
    private TreeNode delete(TreeNode root, int k)
    {   
    	TreeNode temp;
        if (root.getData()==k) {
            if (root.getLeft()==null && root.getRight()==null) {
                //Wanna find the privous node
                return null;
            
            }else if (root.getLeft()==null) {
                temp=root.getRight();
                return temp;
         
            }else if (root.getRight()==null) {
                temp=root.getLeft();
                return temp;
            
            }else{
                temp=root.getRight();
                TreeNode tempReturn=root.getRight();
                while(temp.getLeft()!=null){
                    temp=temp.getLeft();
                }
                temp.setLeft(root.getLeft());
                return tempReturn;
            }
       
        }else if (k<root.getData()) {
            temp=delete(root.getLeft(),k);
            root.setLeft(temp);

        }else{
            temp=delete(root.getRight(),k);
            root.setRight(temp);
        }

        return root;
    }
    

    /* Functions to count number of nodes */
    public int countNodes()
    {
        return countNodes(root);
    }
    /* Function to count number of nodes recursively */
    /**
     * this function intend to count every node and its child node, so
     * each function should be maximum# 3
     * then add them up which is the final answer
     * */
    private int countNodes(TreeNode r)
    {
    	if(r==null){
    		return 0;
    	}else{
    		int count=1;
    		count=count+countNodes(r.getLeft());
    		count=count+countNodes(r.getRight());
    		return count;
    	}
    	

    }

    
    /* Functions to search for an element */
    /**
     * this function intend to search a node
     * simply compare the value ,then decide which way to go
     * finally to find true or false;
     * */
    public boolean search(int val)
    {
        return search(root,val);
    }
    
    /* Function to search for an element recursively */
    private boolean search(TreeNode r, int val)
    {
        if(r==null){
        	return false;
        }
    	if (r.getData()==val) {
            return true;
    	}
        else{
        	if(val<r.getData()){
        	return	search(r.getLeft(),val);
        	}
        	
        	else{
        	return 	search(r.getRight(),val);
        	}

        }

    }
   



	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
