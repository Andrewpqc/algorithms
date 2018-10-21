package graph;

public class Topological {
    private Iterable<Integer> order;

    public Topological(Digraph dg) {
        DirectedCycle dc = new DirectedCycle(dg);
        if (!dc.hasCycle()) {
            DepthFirstOrder dfo = new DepthFirstOrder(dg);
            order = dfo.reversePost();
        }
    }

    public boolean hasCycle() {
        return order == null;
    }

    public Iterable<Integer> topologicalOrder() {
        return order;
    }


    public static void main(String[] args) {
        Digraph dg = new Digraph(8);
        dg.addEdge(0, 1);
        dg.addEdge(1, 2);
        dg.addEdge(2, 3);
        dg.addEdge(3, 4);
        dg.addEdge(4, 1);
        dg.addEdge(5, 6);
        dg.addEdge(6, 7);

        Topological tp = new Topological(dg);
        if (tp.hasCycle()) {
            System.out.println("has cycle");
            return;
        } else {
            System.out.println("the topological order is:");
            for (int i : tp.topologicalOrder()) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}
