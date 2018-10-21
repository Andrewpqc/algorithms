/**
 * 有向图数据类型
 */

package graph;

public class Digraph {
    private int verNum;
    private int edgeNum;
    private Bag<Integer>[] bags;

    public Digraph(int V) {
        verNum = V;
        edgeNum = 0;
        bags = (Bag<Integer>[]) new Bag[V];
        for (int i = 0; i < V; ++i)
            bags[i] = new Bag<Integer>();
    }

    public int V() {
        return verNum;
    }

    public int E() {
        return edgeNum;
    }

    public void addEdge(int s, int d) {
        ++edgeNum;
        bags[s].add(d);
    }

    public Iterable<Integer> adj(int x) {
        return bags[x];
    }

    public Digraph reverse() {
        Digraph rd = new Digraph(verNum);
        for (int i = 0; i < verNum; ++i)
            for (int k : bags[i])
                rd.addEdge(k, i);
        return rd;
    }


    public static void main(String[] args) {
        Digraph dg = new Digraph(5);
        dg.addEdge(0, 1);
        dg.addEdge(1, 2);
        dg.addEdge(2, 3);
        dg.addEdge(3, 4);

        System.out.println(dg.E());
        System.out.println(dg.V());
        System.out.println(dg.reverse().E());
        System.out.println(dg.reverse().V());
    }
}
