// 二分搜索

import java.util.Arrays; //Arrays.sort()

public class BinarySearch {
    public static int rank(int[] arr, int key) {
        Arrays.sort(arr);
        int l = 0;
        int h = arr.length - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (key > arr[mid]) h = mid - 1;
            else if (key < arr[mid]) l = mid + 1;
            else return mid;
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] myarr = {1, 5, 2, 3, 6, 8};
        int key = 9;
        int result = rank(myarr, key);
        System.out.println(result);
    }
}
