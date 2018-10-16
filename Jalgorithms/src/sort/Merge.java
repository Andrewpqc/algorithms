package sort;

public class Merge extends Example {
    private Comparable[] aux;

    public void merge(Comparable[] array, int lo, int mid, int hi) {
        int i = lo;
        int j = mid + 1;
        for (int k = lo; k <= hi; ++k) {
            aux[k] = array[k];
        }

        for (int k = lo; k <= hi; ++k) {
            if (i > mid) array[k] = aux[j++];
            else if (j > hi) array[k] = aux[i++];
            else if (less(aux[j], aux[i])) array[k] = aux[j++];
            else array[k] = aux[i++];
        }
    }

    @Override
    public void sort(Comparable[] arr) {
        aux = new Comparable[arr.length];
        sort(arr, 0, arr.length - 1);
    }

    public void sort(Comparable[] arr, int lo, int hi) {
        if (hi <= lo) return;
        int mid = lo + (hi - lo) / 2;
        sort(arr, lo, mid);
        sort(arr, mid + 1, hi);
        merge(arr, lo, mid, hi);

    }


    public static void main(String[] args) {
        Integer[] array = {1, 2, 3, 5, 2, 100, 25, 65, 25, 35, 64, 85};
        Merge merge = new Merge();
        merge.sort(array);
        merge.show(array);
    }
}

