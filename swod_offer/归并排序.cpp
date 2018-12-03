#include <iostream>
using namespace std;

void merge(int *arr, int low,int mid,int high){
    /*合并两个已经排序的数组*/
    int low1 = low;
    int high1 = mid;
    int low2 = mid+1;
    int high2 = high;

    int* newArr= (int*) malloc(sizeof(int)*(high-low+1));
    int current_index=0;
    while (low1<=high1 && low2<=high2){
        if(arr[low1]>=arr[low2])
            newArr[current_index++]=arr[low2++];
        else newArr[current_index++]=arr[low1++];
    }

    //将剩下的元素直接复制到newArr中
    if(low1 == high1){
        while (low2<=high2){
            newArr[current_index++]=arr[low2++];
        }
    }else{
        while (low1<high1){
            newArr[current_index++]=arr[low1++];
        }
    }

    for(int j=0,i= low;i<=high;++i,++j){
        arr[i]=newArr[j];
    }

    free(newArr);

}

void merge_sort(int* arr,int low, int high){
    if(low<high){
        int mid= (low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}


int main(int argc, char** argv){
    int array[10]={1,0,5,3,4,6,8,2,3,9};
    merge_sort(array,0,9);

    for(int i=0;i<10;++i){
        cout<<array[i]<<" ";
    }

}