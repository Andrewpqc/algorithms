import java.util.Iterator;

public class Bag<Item> implements Iterable<Item> {
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


    public static void main(String[] args) {
        Bag<Integer> bag = new Bag<Integer>();

        bag.add(1);
        bag.add(2);
        bag.add(3);

        System.out.println("size: " + bag.size());

        for (Integer i : bag) {
            System.out.println(i);
        }
    }
}