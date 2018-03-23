/**
 * 计数排序是稳定排序
 **/ 
#include <stdio.h>
#include <stdlib.h>
/**
 * a:带有输入数据的数组
 * b:输入排序后的数组
 * size:数组的大小
 * max:待排序数组中的最大数据值
 **/ 
void counting_sort(int* a,int* b,size_t size,int max){
    //定义辅助数组
    int c[max+1];

    //初始化辅助数组为0
    for(int i=0;i<max+1;i++)
        c[i]=0;
    
    //按照从小到大统计待排序数据出现的次数
    for(int i=0;i<size;i++)
        c[a[i]]=c[a[i]]+1;
    
    //计算比一个数据小的数的个数
    for(int i=1;i<max+1;i++)
        c[i]=c[i]+c[i-1];

    //排序的数据放在b数组中
    for(int i=size-1;i>=0;i--){
        b[c[a[i]]-1]=a[i];
        c[a[i]]=c[a[i]]-1;
    }
}



int main (void){
    int a[10]={5,2,0,6,3,7,8,2,9,10};
    int b[10];
    counting_sort(a,b,10,10);
    for(int i=0;i<10;i++){
        printf("%d ",b[i]);
    }
    return 0;
}