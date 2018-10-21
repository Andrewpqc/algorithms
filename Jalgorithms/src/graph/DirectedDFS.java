/**
 * 有向图的深度优先搜索
 */
package graph;

public class DirectedDFS {
    private boolean[] marked;

    //ddfs.marked(v)
    //从s是否可以到达v
    public DirectedDFS(Digraph dg, int s) {
        marked = new boolean[dg.V()];
        dfs(dg, s);
    }

    //ddfs.marked(v)
    //在source中是否存在一个点可以到达v
    public DirectedDFS(Digraph dg, int[] source) {
        marked = new boolean[dg.V()];
        for (int i = 0; i < source.length; ++i) {
            dfs(dg, source[i]);
        }
    }


    private void dfs(Digraph dg, int s) {
        marked[s] = true;
        for (int k : dg.adj(s)) {
            if (!marked[k]) {
                dfs(dg, k);
            }
        }
    }


    public boolean marked(int x) {
        return marked[x];
    }


    public static void main(String[] args) {
        Digraph dg = new Digraph(8);
        dg.addEdge(0, 1);
        dg.addEdge(1, 2);
        dg.addEdge(2, 3);
        dg.addEdge(3, 4);
        dg.addEdge(5, 6);
        dg.addEdge(6, 7);

        DirectedDFS ddfs = new DirectedDFS(dg, 2);
        System.out.println(ddfs.marked(4));

        int[] s = {1, 6};
        DirectedDFS ddfs2 = new DirectedDFS(dg, s);
        System.out.println(ddfs2.marked(2));
        System.out.println(ddfs2.marked(7));
    }

}
