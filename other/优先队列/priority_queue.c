#include <stdio.h>
#include <stdlib.h>

//调整堆
void max_heapify(int * a,int size,int i){
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;

    //这里要用largest来比较不能用i
    // if(l<size && a[i]<a[l]),写成下面这样
    if(l<size && a[largest]<a[l])
        largest=l;
    if(r<size && a[r]>a[largest])
        largest=r;
    if (largest != i){
        int j=a[i];
        a[i]=a[largest];
        a[largest]=j;
        max_heapify(a,size,largest);
    }
}


//建堆
void build_heap(int * a,int size){
    for(int i=size/2-1;i>=0;i--)
        max_heapify(a,size,i);
    
}
//获取数组a的最大值
int maximum(int*a){
    return a[0];
}

int extract_max(int* a)

int main (void){
    int a[5]={1,2,3,4,5};
    build_heap(a,5);
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }
    return 0;
}