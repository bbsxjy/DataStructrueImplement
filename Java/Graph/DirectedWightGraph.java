package graph;

import java.util.Random;

public class DirectedWightGraph {
	private int[][] edges;
	private int V,E;
	private int[] indegree;
	private Random random;
	
	//constructor with given number of vertices
		public DirectedWightGraph(int V){
			this.V=V;
			this.E=0;
			edges=new int[V][V];
			this.indegree=new int [V];
			
		}
		//constructor with random edges weight and vertices numbers
	    /**
	     * Initializes a random edge-weighted digraph with <tt>V</tt> vertices and <em>E</em> edges.
	     *
	     * @param  V the number of vertices
	     * @param  E the number of edges
	     * @throws IllegalArgumentException if <tt>V</tt> < 0
	     * @throws IllegalArgumentException if <tt>E</tt> < 0
	     */
		public DirectedWightGraph(int V,int E){
			this(V);
			random=new Random();
	        for (int i = 0; i < E; i++) {
	            int v = random.nextInt(V);
	            int w = random.nextInt(V);
	            double weight = .01 * random.nextInt(100);
	            DirectedWeightEdge e = new DirectedWeightEdge(v, w, weight);
	            addEdge(e);
	        }
		}
		
		//validate the desired vertex
		public void isValidVertices(int v){
	        if (v < 0 || v >= V)
	            throw new IndexOutOfBoundsException("vertex " + v + " is not between 0 and " + (V-1));
		}
		
		//add the vertex to another vertex
		public void addEdge(DirectedWeightEdge e){
			int v=e.from();
			int w=e.to();
			if(edges[v][w]==0){
				edges[v][w]=1;
				E++;
				//the numbers of indegree of w increase by 1
				indegree[w]++;
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
	     * Returns the indegree of vertex v.
	     *
	     * @param  v the vertex
	     * @return the degree of vertex v
	     * @throws IndexOutOfBoundsException unless 0 <= v < V
	     */
	    public int indegree(int v) {

	        return indegree[v];
	        
	    }
		
	    /**
	     * Returns the number of directed edges incident from vertex <tt>v</tt>.
	     * This is known as the <em>outdegree</em> of vertex <tt>v</tt>.
	     *
	     * @param  v the vertex
	     * @return the outdegree of vertex <tt>v</tt>
	     * @throws IndexOutOfBoundsException unless 0 <= v < V
	     */

	    public int outdegree(int v) {
	        int count=0;
	    	for (String is : adjacentEdge(v)) {
				if(is!=null){
					count++;
				}
			}
	        return count;
	    }
		
		
		
		
		
		
		
}
