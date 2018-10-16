package sort;

public class Example {
    protected boolean less(Comparable x, Comparable y) {
        return x.compareTo(y) < 0;
    }

    protected void exch(Comparable[] arr, int x, int y) {
        Comparable temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }

    public boolean isSorted(Comparable[] arr) {
        for (int i = 1; i < arr.length; ++i)
            if (arr[i - 1].compareTo(arr[i]) > 0) return false;
        return true;
    }

    public void show(Comparable[] arr) {
        for (int i = 0; i < arr.length; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }


    public  void sort(Comparable[] arr) {
        // remain to impl
    }


}
