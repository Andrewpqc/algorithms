import java.util.Arrays;
//twoSumCount与twoSumCountFast结果要相同
//则需要保持数组a里面的元素各不相同


public class TwoSum {
    public static int twoSumCount(int[] a){
        int N = a.length;
        int cnt =0;
        for(int i =0 ;i<N;++i){
            for(int j=i+1;j<N;++j) {
                if(a[i]+a[j]==0)
                    ++cnt;
            }
        }
        return cnt;
    }


    public static int twoSumCountFast(int[] a){
        Arrays.sort(a);
        int N = a.length;
        int cnt =0;
        for(int i=0;i<N;++i){
            if(BinarySearch.rank1(a,-a[i]) > i)
                ++cnt;
        }
        return cnt;
    }


    public static void main(String[] args) {
        int[] array = {2,3,-3,5,6,1,-1,9,-5};
        System.out.println(twoSumCount(array));
        System.out.println(twoSumCountFast(array));
    }
}
