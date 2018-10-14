public class FixCapacityStackofString {
    private String[] strs;
    private int N;
    private int cap;

    public FixCapacityStackofString(int capacity) {
        strs = new String[capacity];
        cap = capacity;
        N = 0;
    }

    public void push(String s) {
        if (N == cap) {
            System.out.println("stack if full");
            return;
        }
        strs[N++] = s;
    }

    public String pop() {
        if (N == 0) {
            System.out.println("stack is empty");
            return "";
        }
        return strs[(N--) - 1];
    }

    public boolean isEmpty() {
        return N == 0;
    }

    public int size() {
        return N;
    }

    public static void main(String[] args) {
        FixCapacityStackofString s = new FixCapacityStackofString(5);
        s.push("hello");
        s.push("world");
        s.push("python");
        s.push("go");
        s.push("c++");
        s.push("Java");
        System.out.println(s.pop());
        System.out.println(s.pop());
        System.out.println(s.pop());
        System.out.println(s.pop());
        System.out.println(s.pop());
        System.out.println(s.pop());
    }
}
