package graph;

import java.util.Iterator;


class Queue<Item> implements Iterable<Item> {
    private Node head;
    private Node tail;
    private int len_;

    private class Node {
        Item data;
        Node next;
    }

    public Queue() {
        head = new Node();
        tail = new Node();
        head.next = tail;
        tail.next = null;
        len_ = 0;
    }

    public void enqueue(Item item) {
        Node tmp = new Node();
        tmp.data = item;
        tmp.next = null;
        tail.next = tmp;
        tail = tail.next;
        ++len_;
    }

    public Item dequeue() {
        if (len_ == 0) {
            System.out.println("queue is empty");
            System.exit(0);
        }
        Item item = head.next.next.data;
        head = head.next;
        --len_;
        return item;
    }

    public int size() {
        return len_;
    }

    public boolean isEmpty() {
        return len_ == 0;
    }

    @Override
    public Iterator<Item> iterator() {
        return new ListIterator();
    }


    private class ListIterator implements Iterator<Item> {
        private Node h = head;

        @Override
        public Item next() {
            Item item = h.next.next.data;
            h = h.next;
            return item;
        }

        @Override
        public boolean hasNext() {
            return h.next.next != null;
        }

        @Override
        public void remove() {

        }
    }


}


public class BreadthFirstSearch {
    private Queue<Integer> q;
    private int count;
    private boolean marked[];

    /**
     * @param g 需要处理的图
     * @param s 出发点
     */
    public BreadthFirstSearch(Graph g, int s) {
        q = new Queue<Integer>();
        marked = new boolean[g.V()];
        q.enqueue(s);
        while (!q.isEmpty()) {
            int v = q.dequeue();
            count++;
            marked[v] = true;
            for (Integer k : g.adj(v)) {
                if (!marked[k]) {
                    q.enqueue(k);

                }
            }

        }
    }

    public boolean marked(int v) {
        return marked[v];
    }

    public int count() {
        return count;
    }

    public static void main(String[] args) {
        Graph g = new Graph(8);
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(2, 3);
        g.addEdge(3, 4);
        g.addEdge(5, 6);
        g.addEdge(6, 7);

        BreadthFirstSearch bfs = new BreadthFirstSearch(g, 1);
        System.out.println(bfs.count()); // 5

        BreadthFirstSearch bfs2 = new BreadthFirstSearch(g, 7);
        System.out.println(bfs2.count()); // 3
    }
}
