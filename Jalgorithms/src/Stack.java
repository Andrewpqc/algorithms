public class Stack<Item> {
    private Item[] items;
    private int len_;
    private int cap_;

    private void resize(int newCap){
        Item[] temp = (Item[]) new Object[newCap];
        cap_ = newCap;
        len_ =0;
        for(int i=0;i<len_;++i){
            temp[i] = items[i];
        }
        items = temp;
    }

    public Stack(){
        cap_ =1;
        items =(Item[]) new Object[1];
    }

    public void push(Item itm){
        if(len_ == cap_) resize(2*cap_);
        items[len_++] =itm;
    }

    public Item pop() {
        if(len_ < 0.25*cap_) resize(cap_/2);
        return items[(len_--)-1];
    }

    public int size(){
        return len_;
    }

    public int capacity(){
        return cap_;
    }

    public static void main(String[] args) {
        Stack<Integer> s = new Stack<Integer>();
        System.out.println(s.size());
        System.out.println(s.capacity());

        for (int i = 0; i < 10; i++)
            s.push(i);
        for (int i = 0; i < 10; i++)
            System.out.println(s.pop());
    }
}
