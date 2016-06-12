package graph;

public class UndirectedGraph {
	private int[][] edges;
	private int V,E;
	//constructor with given number of vertices
	public UndirectedGraph(int V){
		this.V=V;
		this.E=0;
		edges=new int[V][V];
	}
	//constructor copy another graph
	public UndirctedGraph(UndirctedGraph g){}
	
	//validate the desired vertex
	public void isValidVertices(int v){
        if (v < 0 || v >= V)
            throw new IndexOutOfBoundsException("vertex " + v + " is not between 0 and " + (V-1));
	}
	
	//add the vertex to another vertex
	public void addEdge(int v, int w){
		isValidVertices(v);
		isValidVertices(w);
		
		
		if(edges[v][w]==0){
			edges[v][w]=1;
			E++;
		}else{
			System.out.println("("+v+","+w+")"+" Edge already exsists");
		}
			
	}
	//return the vertices adjacent to vertex
	public String[] adjacentEdge(int v){
		String[] temp=new String[V];
		int count=0;
		for(int i =0; i<edges[v].length;i++){
			if(edges[v][i]!=0){
				temp[count]="("+v+","+i+")";
				count++;
			}
		}
		return temp;
	}
	
	
    /**
     * Returns the number of vertices in this graph.
     *
     * @return the number of vertices in this graph
     */
    public int V() {
        return V;
    }
    
    /**
     * Returns the number of edges in this graph.
     *
     * @return the number of edges in this graph
     */
    public int E() {
        return E;
    }
	
    /**
     * Returns the degree of vertex v.
     *
     * @param  v the vertex
     * @return the degree of vertex v
     * @throws IndexOutOfBoundsException unless 0 <= v < V
     */
    public int degree(int v) {
        int count=0;
    	for (String is : adjacentEdge(v)) {
			if(is!=null){
				count++;
			}
		}
        return count;
        
    }
	

	
	
	
	
	
	
	
	
	
	
	
	
}
