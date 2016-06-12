package graph;

public class GraphTester {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		DirectedWightGraph g=new DirectedWightGraph(10,9);

		
		System.out.println("total edges: "+g.E());
		
		String[] temp=g.adjacentEdge(0);
		for (String string : temp) {
			if(string!=null)
			System.out.println(string);
		}
		System.out.println("this edge has "+g.indegree(0)+" adjacent edges!");
	}

}
