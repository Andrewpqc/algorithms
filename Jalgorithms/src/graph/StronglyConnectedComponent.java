/**
 * 强联通分量的计算 Korasaju算法
 */

package graph;

public class StronglyConnectedComponent {
    private boolean[] marked;
    private int[] id;//强连通分量的标识符
    private int count; //连通分量数

    public StronglyConnectedComponent(Digraph dg) {
        marked = new boolean[dg.V()];
        id = new int[dg.V()];
        DepthFirstOrder dfo = new DepthFirstOrder(dg.reverse());
        for (int k : dfo.reversePost())//dg的反向图的的逆后序排列
            if (!marked[k]) {
                dfs(dg, k);
                ++count;
            }
    }

    public void dfs(Digraph dg, int s) {
        marked[s] = true;
        id[s] = count;
        for (int v : dg.adj(s))
            if (!marked[v]) dfs(dg, v);
    }

    public boolean stronglyConnected(int x, int y) {
        return id[x] == id[y];
    }

    public int id(int x) {
        return id[x];
    }

    public int count() {
        return count;
    }

    public static void main(String[] args) {
        Digraph dg = new Digraph(8);
        dg.addEdge(0, 1);
        dg.addEdge(1, 2);
        dg.addEdge(2, 3);
        dg.addEdge(3, 4);
        dg.addEdge(4, 0);
        dg.addEdge(5, 6);
        dg.addEdge(6, 7);
        dg.addEdge(7, 5);

        StronglyConnectedComponent scc = new StronglyConnectedComponent(dg);
        System.out.println(scc.count());
        System.out.println(scc.stronglyConnected(1, 7));
        System.out.println(scc.stronglyConnected(1, 4));
    }
}
