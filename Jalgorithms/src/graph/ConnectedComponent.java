package graph;

public class ConnectedComponent {
    private boolean[] marked;
    private int[] id;
    private int count;

    public ConnectedComponent(Graph g) {
        marked = new boolean[g.V()];
        id = new int[g.V()];
        count = 0;
        for (int i = 0; i < g.V(); ++i) {
            if (!marked[i]) {
                dfs(g, i);
                ++count;
            }
        }
    }

    private void dfs(Graph g, int s) {
        marked[s] = true;
        id[s] = count;
        for (int k : g.adj(s)) {
            if (!marked[k]) {
                dfs(g, k);
            }
        }
    }


    public boolean connected(int x, int y) {
        return id[x] == id[y];
    }


    public int count() {
        return count;
    }

    public int id(int x) {
        return id[x];
    }

    public static void main(String[] args) {
        Graph g = new Graph(8);
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(2, 3);
        g.addEdge(3, 4);
        g.addEdge(5, 6);
        g.addEdge(6, 7);

        ConnectedComponent cc = new ConnectedComponent(g);
        System.out.println(cc.connected(1, 2));
        System.out.println(cc.connected(3, 7));
        System.out.println(cc.count());

        Bag<Integer>[] bags = (Bag<Integer>[]) new Bag[cc.count()];
        for (int i = 0; i < cc.count(); ++i)
            bags[i] = new Bag<Integer>();

        for (int i = 0; i < g.V(); ++i)
            bags[cc.id(i)].add(i);

        for (int i = 0; i < cc.count(); ++i) {
            for (Integer j : bags[i]) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
}
