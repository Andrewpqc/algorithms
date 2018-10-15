public class LinkedList<Item> {
    private Node head;
    private Node tail;
    private int len_;

    private class Node {
        Node next;
        Item data;
    }

    public LinkedList() {
        head = new Node();
        tail = new Node();
        head.next=tail;
        tail.next=null;
        len_=0;
    }

    public void push(Item item){
        Node node = new Node();
        node.data = item;
        node.next=null;
        tail = node;
    }


    public boolean isEmpty(){
        return len_ == 0;
    }

}
