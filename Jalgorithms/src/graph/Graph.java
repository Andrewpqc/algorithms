package graph;

import java.util.Iterator;

class Bag<Item> implements Iterable<Item> {
    private Node first;
    private int len_ = 0;

    private class Node {
        Item item;
        Node next;
    }

    public void add(Item item) {
        Node oldFirst = first;
        first = new Node();
        first.item = item;
        first.next = oldFirst;
        ++len_;
    }

    public boolean isEmpty() {
        return len_ == 0;
    }


    public int size() {
        return len_;
    }


    @Override
    public Iterator<Item> iterator() {
        return new ListIterator();
    }

    private class ListIterator implements Iterator<Item> {
        private Node current = first;

        @Override
        public boolean hasNext() {
            return current != null;
        }

        @Override
        public Item next() {
            Item item = current.item;
            current = current.next;
            return item;
        }

        @Override
        public void remove() {

        }
    }
}


/**
 * 图的表示
 */
public class Graph {
    private Bag<Integer>[] adj;
    private int edgeNum;
    private int verNum;

    public Graph(int V) {
        adj = (Bag<Integer>[]) new Bag[V];
        for(int i = 0; i<V ;++i)
            adj[i] = new Bag<Integer>();
        verNum = V;
        edgeNum = 0;
    }

    public int V() {
        return verNum;
    }

    public int E() {
        return edgeNum;
    }

    public void addEdge(int a, int b) {
        adj[a].add(b);
        adj[b].add(a);
        ++edgeNum;
    }

    public Iterable<Integer> adj(int v) {
        return adj[v];
    }

    public static void main(String[] args){
        Graph g =new Graph(5);
        g.addEdge(0,1);
        g.addEdge(1,2);
        g.addEdge(2,3);
        g.addEdge(3,4);

        System.out.println(g.E());
        System.out.println(g.V());
        for(Integer b:g.adj(2)){
            System.out.println(b);
        }
    }
}
