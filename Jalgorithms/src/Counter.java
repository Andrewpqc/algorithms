public class Counter {
    private int count_;
    private final String name_; //因为name_初始化之后就不会改变了，所以这里使用final

    public Counter(String name) {
        name_ = name;
        count_ = 0;
    }

    public int getCount() {
        return count_;
    }

    public String getName() {
        return name_;
    }

    public void increment() {
        ++count_;
    }

    public void decrement() {
        --count_;
    }

    @Override
    public String toString() {
        return name_ + ":" + count_;
    }

    public static void main(String[] args) {
        Counter c = new Counter("count1");
        c.increment();
        c.decrement();
        c.increment();
        System.out.println(c.toString());
    }
}
