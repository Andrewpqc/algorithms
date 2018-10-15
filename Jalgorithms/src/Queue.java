import java.util.Iterator;

public class Queue<Item> implements Iterable<Item> {
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


    public static void main(String[] args) {
        Queue<String> q = new Queue<String>();
        q.enqueue("a");
        q.enqueue("b");
        q.enqueue("c");
        q.enqueue("d");
        q.enqueue("e");

        for (String i : q) {
            System.out.println(i);
        }

        System.out.println(q.dequeue());
        System.out.println(q.dequeue());
        System.out.println(q.dequeue());
        System.out.println(q.dequeue());
        System.out.println(q.dequeue());
        System.out.println(q.dequeue());
    }
}
