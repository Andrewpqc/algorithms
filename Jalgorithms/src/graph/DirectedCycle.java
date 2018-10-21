/**
 * 检查一个有向图中是否有有向环,如果有找出其中的一个环的路径
 */
package graph;

public class DirectedCycle {
    private boolean[] marked;
    private int[] edgeTo;
    private Stack<Integer> cycle;
    private boolean[] onStack;

    public DirectedCycle(Digraph dg) {
        onStack = new boolean[dg.V()];
        edgeTo = new int[dg.V()];
        marked = new boolean[dg.V()];

        for (int i = 0; i < dg.V(); ++i)
            if (!marked[i]) dfs(dg, i);
    }

    private void dfs(Digraph dg, int s) {
        onStack[s] = true;
        marked[s] = true;
        for (int i : dg.adj(s)) {
            if (this.hasCycle()) return;
            else if (!marked[i]) {
                edgeTo[i] = s;
                dfs(dg, i);
            } else if (onStack[i]) {
                cycle = new Stack<>();
                for (int x = s; x != i; x = edgeTo[x])
                    cycle.push(x);
                cycle.push(i);
                cycle.push(s);
            }
            onStack[s] = false;
        }
    }

    public boolean hasCycle() {
        return cycle != null;
    }

    public Iterable<Integer> cycle() {
        return cycle;
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

        DirectedCycle dc = new DirectedCycle(dg);
        if (dc.hasCycle()) {
            for (int i : dc.cycle)
                System.out.print(i + " ");
            System.out.println();
        } else {
            System.out.println("no cycle");
        }
    }
}
