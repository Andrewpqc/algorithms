package sort;

//选择排序
//每次都去选择最小的元素，放在前面
public class Selection extends Example {
    @Override
    public void sort(Comparable[] arr) {
       int N = arr.length;
       for(int i=0;i<N;++i){
           int minIndex = i;
           for(int j=i+1;j<N;++j){
               if(less(arr[j],arr[minIndex])) minIndex=j;
           }
           exch(arr,i,minIndex);
       }
    }

    public static void main(String[] args) {
        Integer [] array= {1,2,3,5,2};
        Selection selection = new Selection();
        selection.sort(array);
        selection.show(array);
    }
}
