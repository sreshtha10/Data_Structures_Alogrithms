// node begin from 0
class Graph{
    private int v; // total vertices
    private LinkedList<Integer> adj[];
    private boolean visited[];
    
    Graph(int v){
        this.v = v;
        adj = new LinkedList[v];
        visited = new boolean[v];
        for(int i=0;i<v;i++){
            adj[i] = new LinkedList<Integer>();
            visited[i] = false;
        }
    }
    
    public void add_edge(int start,int end){
        adj[start].add(end);
    }
    
    
    public void display_adjaceny_list(){
        for(int i=0;i<v;i++){
            System.out.print(i +" -> ");
            for(int next:adj[i]){
                System.out.print(next+ "  ");
            }
            System.out.println();
        }
    }
    
    
    public void dfs(int source){
        //mark all visited to false
        for(int i=0;i<v;i++){
            visited[i] = false;
        }
        dfs_rec(source);
    } 
    
    private void dfs_rec(int source){
        try{
            visited[source] = true;
            System.out.print(source+"   ");
            for(int neighbour: adj[source]){
                if(!visited[neighbour]){
                    dfs_rec(neighbour);
                }
            }
        }
        catch(Exception e){
            //error -> INVALID node.
        }
    }
    
    
    public void bfs(int source){
        
        //mark all visited to false
         for(int i=0;i<v;i++){
            visited[i] = false;
        }
        
        try{
            Queue<Integer> queue = new LinkedList<Integer>();
            visited[source] = true;
            queue.add(source);

            while(!queue.isEmpty()){
                int curr_node= queue.poll();
                System.out.print(curr_node+"  ");
                for(int neighbour:adj[curr_node]){
                    if(!visited[neighbour]){
                        queue.add(neighbour);
                        visited[neighbour] = true;
                    }
                }
            }
        }
        catch(Exception e){
            //error -> INVALID node.
        }
        
    } 
    
    
    
    public void count_disconnected_components(){
        //mark all visited to false
        for(int i=0;i<v;i++){
            visited[i] = false;
        }
        
        int count =0;
        
        for(int i=0;i<v;i++){
            if(!visited[i]){
                count++;
                dfs_rec(i);
            }
        }  
        System.out.println("\nNo of disconnected Components = "+count);
    }
    
    
    
    
    public boolean isCyclic_using_bfs(){
        /*flag ->
         -1 -> Node unvisited and not in the queue
         1 -> Node is visited and not in the queue
         0 -> Node is in the queue.
        
         Logic -> If we find any neighbour which is already in the queue then there is a cycle.*/
        int flag[] = new int[v];
        for(int i=0;i<v;i++){
            flag[i] = -1;
        }
        
    
        int source = 0;
        Queue<Integer> queue = new LinkedList<Integer>();
        
        flag[source]=0;
        
        queue.add(source);
        
        while(!queue.isEmpty()){
            int curr_node= queue.poll();
            flag[curr_node] = 1;
            for(int next:adj[curr_node]){
                if(flag[next] == -1){
                    queue.add(next);
                    flag[next] = 0;
                }
                if(flag[next] == 0){
                    // cycle detected
                    return true;
                }
            }
        }
        return false;
    }

    

    public boolean isCyclic_using_dfs(){
    /*flag ->
         -1 -> Node unvisited and not in the queu
         1 -> Node is visited and not in the queue
         0 -> Node is in the queue.        
         Logic -> If we find any neighbour which is already in the stack then there is a cycle.*/
        
        int flag[] = new int[v];
        for(int i=0;i<v;i++){
            flag[i] = -1;
        }
        
        dfs_cycles(flag,0);
    
    
    }
    
    
    private boolean dfs_cyclic(int[] flag,int source){
    
        adj[source]= 0;
        for(int next:adj[source]){
            
        
        }
    
    }
    
    
    
}

public class Main {
    public static void main(String[] args) {
        
        Graph g = new Graph(7);
        g.add_edge(0,3);
        g.add_edge(0,1);
        g.add_edge(1,2);
        g.add_edge(1,3);
        g.add_edge(1,5);
        g.add_edge(1,6);
        g.add_edge(2,4);
        g.add_edge(2,3);
        g.add_edge(2,5);
        g.add_edge(3,4);
        g.add_edge(4,6);
        
        
        g.display_adjaceny_list();
        
        g.bfs(0);
        
        System.out.println();
        
        g.dfs(0);
        
        System.out.println();
        
        
        Graph a = new Graph(3);
        a.add_edge(0,1);
        
        a.count_disconnected_components();
        
        g = new Graph(6);
        g.add_edge(0,1);
        g.add_edge(1,2);
        g.add_edge(1,4);
        g.add_edge(2,3);
        g.add_edge(3,4);
        g.add_edge(3,5);
        
        
        System.out.println(g.isCyclic_using_bfs());
        
        
        
    }
}
