package sort;

public class Quick extends Example {

    @Override
    public void sort(Comparable[] arr) {
        sort(arr, 0, arr.length - 1);
    }

    public void sort(Comparable[] arr, int lo, int hi) {
        if (lo >= hi) return;
        Comparable base = arr[lo];
        int first = lo;
        int last = hi;
        while (first < last) {
            while (first < last && less(base, arr[last])) {
                --last;
            }
            arr[first] = arr[last];

            while (first < last && less(arr[first], base)) {
                ++first;
            }
            arr[last] = arr[first];
        }
        arr[first] = base;
        sort(arr, lo, first - 1);
        sort(arr, first + 1, hi);
    }


    public static void main(String[] args) {
        Integer[] array = {1, 2, 3, 5, 2, 100, 25, 65, 25, 35, 64, 85};
        Quick quick = new Quick();
        quick.sort(array);
        quick.show(array);
    }
}
