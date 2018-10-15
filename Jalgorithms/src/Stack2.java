import java.util.Iterator;

public class Stack2<Item> implements Iterable<Item> {
    private int len_;
    private Node head;


    private class Node {
        Item data;
        Node next;
    }

    public Stack2() {
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
        if(len_ == 0){
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


    public static void main(String[] args) {
        Stack2<String> s = new Stack2<String>();
        s.push("hello");
        s.push("world");
        s.push("java");
        for (String str : s) {
            System.out.println(str);
        }

        System.out.println(s.pop());
        System.out.println(s.pop());
        System.out.println(s.pop());
        System.out.println(s.pop());
    }
}
