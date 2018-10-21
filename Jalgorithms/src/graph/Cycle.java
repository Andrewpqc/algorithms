/**
 * 检测图是否为无环图
 */
package graph;

public class Cycle {
    private boolean[] marked;
    private boolean hasCycle;

    public Cycle(Graph g) {
        marked = new boolean[g.V()];
        for (int s = 0; s < g.V(); ++s) {
            if (!marked[s]) {
                dfs(g, s, s);
            }
        }
    }

    private void dfs(Graph g, int x, int y) {
        marked[x] = true;
        for (int w : g.adj(x))
            if (!marked[w]) dfs(g, w, x);
            else if (w != y) hasCycle = true;
    }

    public boolean isHasCycle() {
        return hasCycle;
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

        Cycle c = new Cycle(g);
        System.out.println(c.isHasCycle());

    }
}
