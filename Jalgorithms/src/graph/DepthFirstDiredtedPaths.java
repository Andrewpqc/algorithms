//有向图的深度优先路径搜索

package graph;

public class DepthFirstDiredtedPaths {
    private boolean[] marked;
    private int[] pathTo;
    private final int src;

    public DepthFirstDiredtedPaths(Digraph dg, int s) {
        marked = new boolean[dg.V()];
        pathTo = new int[dg.V()];
        src = s;
        dfs(dg, s);
    }

    private void dfs(Digraph dg, int s) {
        marked[s] = true;
        for (int k : dg.adj(s)) {
            if (!marked[k]) {
                pathTo[k] = s;
                dfs(dg, k);
            }
        }
    }

    public boolean hasPathTo(int d) {
        return marked[d];
    }

    public Iterable<Integer> pathTo(int d) {
        if (!hasPathTo(d)) return null;
        Stack<Integer> s = new Stack<>();
        for (int i = d; i != src; i = pathTo[i])
            s.push(i);
        s.push(src);
        return s;
    }


    public static void main(String[] args) {
        Digraph dg = new Digraph(8);
        dg.addEdge(0, 1);
        dg.addEdge(1, 2);
        dg.addEdge(2, 3);
        dg.addEdge(3, 4);
        dg.addEdge(5, 6);
        dg.addEdge(6, 7);

        DepthFirstDiredtedPaths dfdp = new DepthFirstDiredtedPaths(dg, 1);
        if (dfdp.hasPathTo(4)) {
            for (int i : dfdp.pathTo(4)) //从1出发到4的路径
                System.out.print(i + " ");
            System.out.println();
        } else {
            System.out.println("no path");
        }

        if (dfdp.hasPathTo(7)) {
            for (int i : dfdp.pathTo(7)) //从1出发到7的路径
                System.out.print(i + " ");
            System.out.println();
        } else {
            System.out.println("no path");
        }
    }

}
