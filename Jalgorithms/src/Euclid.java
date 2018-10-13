//欧几里的算法求最大公约数
public class Euclid {
    public static int gcd(int a, int b) {
        if (b == 0) return a;
        int r = a % b;
        return gcd(b, r);
    }


    public static void main(String[] args) {
        int result = gcd(12, 15);
        System.out.println(result);

    }
}
