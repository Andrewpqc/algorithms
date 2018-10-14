// 二分搜索

import java.util.Arrays; //Arrays.sort() 默认从小到大排序

public class BinarySearch {
    public static int rank1(int[] arr, int key) {
        int l = 0;
        int h = arr.length - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (key < arr[mid])      h = mid - 1;
            else if (key > arr[mid]) l = mid + 1;
            else                     return mid;
        }
        return -1;
    }

    public static int rank2(int[] arr, int l, int h, int key) {
        if (l > h) return -1;
        int mid = l + (h - l) / 2;
        if (key < arr[mid])      return rank2(arr, l, mid - 1, key);
        else if (key > arr[mid]) return rank2(arr, mid + 1, h, key);
        else                     return mid;
    }

    public static void main(String[] args) {
        int[] myarr = {1, 5, 2, 3, 6, 8};
        Arrays.sort(myarr);  //从小到大排序
        int key = 2;
        int result1 = rank1(myarr, key);
        int result2 = rank2(myarr, 0, myarr.length - 1, key);
        System.out.println(result1);
        System.out.println(result2);
    }
}
