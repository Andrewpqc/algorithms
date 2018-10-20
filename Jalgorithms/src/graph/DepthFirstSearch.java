package graph;


public class DepthFirstSearch {
    private boolean[] marked;
    private int count;

    /**
     * @param g 需要处理的图
     * @param s 起点
     */
    public DepthFirstSearch(Graph g, int s) {
        marked = new boolean[g.V()];
        count = 0;
        dfs(g, s);
    }

    private void dfs(Graph g, int s) {
        if (marked[s]) return;
        marked[s] = true;
        ++count;
        for (Integer v : g.adj(s)) {
            dfs(g, v);
        }
    }


    public int count() {
        return count;
    }


    public boolean marked(int v) {
        return marked[v];
    }


    public static void main(String[] args) {
        Graph g = new Graph(8);
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(2, 3);
        g.addEdge(3, 4);
        g.addEdge(5, 6);
        g.addEdge(6, 7);

        DepthFirstSearch dfs = new DepthFirstSearch(g, 1);
        System.out.println(dfs.count()); // 5

        DepthFirstSearch dfs2 = new DepthFirstSearch(g, 7);
        System.out.println(dfs2.count()); // 3
    }
}
