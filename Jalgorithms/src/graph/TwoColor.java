/**
 * 检测一个图是否为二分图
 */

package graph;

public class TwoColor {
    private boolean[] marked;
    private boolean[] color;
    private boolean isTwoColor = true;


    public TwoColor(Graph g){
        marked = new boolean[g.V()];
        color = new boolean[g.V()];
        for(int i=0;i<g.V();++i){
            if(!marked[i]){
                dfs(g,i);
            }
        }
    }

    private void dfs(Graph g, int s){
        marked[s]=true;
        for(Integer k : g.adj(s)){
            if(!marked[k]){
                color[k]=!color[s];
                dfs(g,k);
            }
            else if(color[k]==color[s]) isTwoColor=false;
        }
    }

    public boolean isTwoColor() {
        return isTwoColor;
    }


    public static void main(String[] args) {
        Graph g = new Graph(8);
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(2, 3);
        g.addEdge(3, 4);
        g.addEdge(4, 0);
        g.addEdge(5, 6);
        g.addEdge(6, 7);

        TwoColor tc = new TwoColor(g);
        System.out.println(tc.isTwoColor());
    }
}
