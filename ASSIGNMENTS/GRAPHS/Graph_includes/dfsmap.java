import java.util.*;
public class dfsmap {
	
	static void dfsprint(int nodes,Map<Integer,ArrayList<Integer>> g)
	{
		Stack<Integer> st=new Stack<>();
		
		boolean[] visited=new boolean[nodes];
		for(int i=0;i<nodes;i++)
		     visited[i]=true;
		
	    int output[]=new int[nodes];
	    
		int inc=1;
		
		st.push(1);
		visited[1]=false;
		output[0]=1;
		
		while(!st.empty())
		 {
			int flag=0;
			int top=st.peek();
			
			ArrayList<Integer> map=g.get(top);
		
		    for(int x:map)
		    {
			    if(visited[x])
			     {
			       st.push(x);
			       output[inc++]=x;
			       visited[x]=false;
			       flag=1;
			       break;
			     }
		    }
		    if(flag==0)
		       st.pop();		
		 }
		
		for(int k=0;k<nodes;k++)
      		System.out.print(output[k]+" ");
	}
	
	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		int nodes=sc.nextInt();
		int edge=sc.nextInt();
		
		Map<Integer,ArrayList<Integer>> g=new TreeMap<>();
		for(int i=0;i<=nodes;i++)
		  g.put(i,new ArrayList<Integer>());
		
		for(int i=1;i<=edge;i++)
		{
			int u=sc.nextInt();
			int v=sc.nextInt();
			g.get(u).add(v);
			g.get(v).add(u);
		}
		dfsprint(nodes,g);
		sc.close();
	}
}