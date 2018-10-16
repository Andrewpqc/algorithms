package sort;

public class Shell extends Example {
    public void sort(Comparable[] arr) {
        int N = arr.length;
        int h = 1;
        while (h < N / 3) h = 3 * h + 1;
        while (h >= 1) {
            for (int i = h; i < N; ++i) {
                for (int j = i; j >= h && less(arr[j], arr[j - h]); j -= h) {
                    exch(arr, j, j - h);
                }
                h = h / 3;
            }
        }
    }

    public static void main(String[] args){
        Integer[] array = {1, 2, 3, 5, 2,100,25,65,25,35,64,85};
        Shell shell = new Shell();
        shell.sort(array);
        shell.show(array);
    }
}
