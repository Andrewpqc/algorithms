import java.util.Arrays;

public class ThreeSum {
    public static int threeSumCount(int[] a) {
        int N = a.length;
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                for (int k = j + 1; k < N; ++k) {
                    if (a[i] + a[j] == 0)
                        ++cnt;
                }
            }
        }
        return cnt;
    }


    public static int threeSumCountFast(int[] a) {
        Arrays.sort(a);
        int N = a.length;
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (BinarySearch.rank1(a, -a[j] - a[i]) > j)
                    ++cnt;
            }
        }
        return cnt;
    }


    public static void main(String[] args) {
        int[] array = {1, 2, -3, 5, -2, 9, 20, -11};
        System.out.println(threeSumCount(array));
        System.out.println(threeSumCountFast(array));
    }
}
