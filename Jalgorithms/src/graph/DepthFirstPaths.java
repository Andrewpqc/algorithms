package graph;

import java.util.Iterator;

class Stack<Item> implements Iterable<Item> {
    private int len_;
    private Node head;


    private class Node {
        Item data;
        Node next;
    }

    public Stack() {
        len_ = 0;
        head = new Node();
        head.next = null;
    }

    public void push(Item item) {
        Node tmp = new Node();
        tmp.data = item;
        tmp.next = head.next;
        head.next = tmp;
        ++len_;
    }

    public Item pop() {
        if (len_ == 0) {
            System.out.println("stack is full");
            System.exit(1);
        }
        Node first = head.next;
        --len_;
        head = head.next;
        return first.data;
    }


    public boolean isEmpty() {
        return len_ == 0;
    }

    public int size() {
        return len_;
    }


    @Override
    public Iterator<Item> iterator() {
        return new ReverseLinkListIterator();
    }

    private class ReverseLinkListIterator implements Iterator<Item> {
        private Node h = head;

        @Override
        public boolean hasNext() {
            return h.next != null;
        }

        @Override
        public Item next() {
            Item item = h.next.data;
            h = h.next;
            return item;
        }

        @Override
        public void remove() {

        }
    }
}


public class DepthFirstPaths {
    private boolean[] marked;
    private int[] pathTo;
    private int src;    //起点

    public DepthFirstPaths(Graph g, int s) {
        marked = new boolean[g.V()];
        pathTo = new int[g.V()];
        int src = s;
        dfs(g, s);
    }

    private void dfs(Graph g, int s) {
        marked[s] = true;
        for (int k : g.adj(s)) {
            if (!marked[k]) {
                pathTo[k] = s;
                dfs(g, k);
            }
        }
    }

    public boolean hasPathTo(int dst) {
        return marked[dst];
    }

    public Iterable<Integer> pathTo(int dst) {
        if (!hasPathTo(dst)) return null;
        Stack<Integer> path = new Stack();

        for (int i = dst; i != src; i = pathTo[i])
            path.push(i);
//        path.push(src);

        return path;
    }


    public static void main(String[] args) {
        Graph g = new Graph(8);
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(2, 3);
        g.addEdge(3, 4);
        g.addEdge(5, 6);
        g.addEdge(6, 7);

        DepthFirstPaths dfp = new DepthFirstPaths(g, 1);
        if (dfp.pathTo(4) == null) {
            System.out.println("no path");
        } else {
            for (Integer path : dfp.pathTo(4))
                System.out.print(path + "-");
        }
        System.out.println();

        DepthFirstPaths dfp2 = new DepthFirstPaths(g, 7);
        if (dfp2.pathTo(6) == null) {
            System.out.println("no path");
        } else {
            for (Integer path : dfp2.pathTo(6))
                System.out.print(path + "-");
        }
        System.out.println();
    }

}
