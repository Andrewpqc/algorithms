package sort;

//插入排序

public class Insertion extends Example {
    @Override
    public void sort(Comparable[] arr) {
        int N = arr.length;
        for (int i = 1; i < N; ++i) {
            int j = i - 1;
            while (j >= 0 && less(arr[j + 1], arr[j])) {
                exch(arr, j + 1, j);
                --j;
            }
        }
    }

    //逐个移动比交换更快
    public void sort2(Comparable[] arr) {
        int N = arr.length;
        for (int i = 1; i < N; ++i) {
            int j = i - 1;
            Comparable temp = arr[i];
            while (j >= 0 && less(arr[j + 1], arr[j])) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = temp;
        }
    }

    public static void main(String[] args) {
        Integer[] array = {1, 2, 3, 5, 2};
        Insertion insertion = new Insertion();
//        insertion.sort(array);
        insertion.sort2(array);
        insertion.show(array);
    }
}
