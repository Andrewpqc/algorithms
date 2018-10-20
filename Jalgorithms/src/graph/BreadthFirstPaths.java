package graph;

import graph.Queue;
import graph.Stack;

public class BreadthFirstPaths {
    private boolean[] marked;
    private int[] pathTo;
    final private int src;

    public BreadthFirstPaths(Graph g, int s) {
        marked = new boolean[g.V()];
        pathTo = new int[g.V()];
        src = s;
        Queue<Integer> q = new Queue<Integer>();
        marked[s] = true;
        q.enqueue(s);
        while (!q.isEmpty()) {
            int v = q.dequeue();
            marked[v] = true;
            for (int i : g.adj(v)) {
                if (!marked[i]) {
                    pathTo[i] = v;
                    marked[i] = true;
                    q.enqueue(i);
                }

            }
        }
    }

    public boolean hasPathTo(int k) {
        return marked[k];
    }

    public Iterable<Integer> pathTo(int k) {
        Stack<Integer> s = new Stack<Integer>();
        if (!hasPathTo(k)) return null;
        for (int x = k; x != src; x = pathTo[x])
            s.push(x);
        s.push(src);
        return s;
    }

    public static void main(String[] args) {
        Graph g = new Graph(8);
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(2, 3);
        g.addEdge(3, 4);
        g.addEdge(5, 6);
        g.addEdge(6, 7);

        BreadthFirstPaths bfp = new BreadthFirstPaths(g, 1);
        if (bfp.pathTo(4) == null) {
            System.out.print("no path");
        } else {
            for (Integer path : bfp.pathTo(4))
                System.out.print(path + "-");
        }
        System.out.println();

        BreadthFirstPaths bfp2 = new BreadthFirstPaths(g, 7);
        if (bfp2.pathTo(6) == null) {
            System.out.print("no path");
        } else {
            for (Integer path : bfp2.pathTo(6))
                System.out.print(path + "-");
        }
        System.out.println();
    }
}
