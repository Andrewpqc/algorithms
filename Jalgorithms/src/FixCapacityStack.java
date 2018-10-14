//定长泛型栈
public class FixCapacityStack<Item> {
    private Item[] items;
    private int len_;
    private int cap_;


    public FixCapacityStack(int cap) {
        // items = new Item[cap];
        //java中创建泛型数组是不被允许的
        //需要进行类型转换,像下面这样:
        items = (Item[]) new Object[cap];

        cap_ = cap;
        len_ = 0;
    }

    public void push(Item itm) {
        if (len_ == cap_) {
            System.out.println("stack if full");
            return;
        }
        items[len_++] = itm;
    }

    public Item pop() {
        if (len_ == 0) {
            System.out.println("stack is empty");
            return null;
        }
        return items[(len_--) - 1];
    }

    public boolean isEmpty() {
        return len_ == 0;
    }

    public int size() {
        return len_;
    }

    public static void main(String[] args) {
        FixCapacityStack<Integer> s = new FixCapacityStack<Integer>(3);
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        System.out.println(s.pop());
        System.out.println(s.pop());
        System.out.println(s.pop());
        System.out.println(s.pop());
    }


}
