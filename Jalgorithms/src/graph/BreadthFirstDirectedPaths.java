/**
 * 有向图的广度优先路径搜索
 */
package graph;

public class BreadthFirstDirectedPaths {
    private boolean[] marked;
    private final int src;
    private int[] pathTo;

    public BreadthFirstDirectedPaths(Digraph dg, int s) {
        marked = new boolean[dg.V()];
        pathTo = new int[dg.V()];
        src = s;
        Queue<Integer> queue = new Queue<>();
        queue.enqueue(s);
        while (!queue.isEmpty()) {
            int queueItem = queue.dequeue();
            marked[queueItem] = true;
            for (int k : dg.adj(queueItem))
                if (!marked[k]) {
                    pathTo[k] = queueItem;
                    queue.enqueue(k);
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

        BreadthFirstDirectedPaths bfdp = new BreadthFirstDirectedPaths(dg, 1);
        if (bfdp.hasPathTo(4)) {
            for (int i : bfdp.pathTo(4)) //从1出发到4的路径
                System.out.print(i + " ");
            System.out.println();
        } else {
            System.out.println("no path");
        }

        if (bfdp.hasPathTo(7)) {
            for (int i : bfdp.pathTo(7)) //从1出发到7的路径
                System.out.print(i + " ");
            System.out.println();
        } else {
            System.out.println("no path");
        }

    }
}
