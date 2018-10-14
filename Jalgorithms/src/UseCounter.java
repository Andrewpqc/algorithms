public class UseCounter {

    public static Counter max(Counter x, Counter y) {
        if(x.getCount() > y.getCount()) return x;
        else                            return y;
    }

    public static void changeCounterObject(Counter x){
        x.increment();
    }

    public static void main(String[] args) {
        Counter c = new Counter("count1");
        c.increment();
        System.out.println(c);

        //c,c2引用了同一个对象
        Counter c2 = c;
        c2.decrement();
        System.out.println(c);
        System.out.println(c2);


        Counter ca= new Counter("ca");
        Counter cb = new Counter("cb");
        ca.increment();
        System.out.println(max(ca,cb).getName());

        Counter cc= new Counter("cc");
        cc.increment();
        System.out.println(cc);

        changeCounterObject(cc);
        System.out.println(cc);
    }
}
