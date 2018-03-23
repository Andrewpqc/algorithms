/**
 * 归并排序
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//合并array[a-b],array[b+1,c],其中这两个数组已经按相同规则排好序
void merge(int *array,int a,int b,int c){
    //lengthL,lengthR都比所要容纳的数组长度多一个，这一个是用来存放哨兵值的
    int lengthL=b-a+1;
    int lengthR=c-b;

    //动态分配创建两个数组存储原数组中的数据，防止被覆盖
    int * L=(int*)malloc((lengthL+1)*sizeof(int));
    int * R=(int*)malloc((lengthR+1)*sizeof(int));

    //填充L,R
    for(int i=0;i<lengthL;i++)
        L[i]=array[a+i];
    L[lengthL]=INT_MAX;//哨兵
    for(int j=0;j<lengthR;j++)
        R[j]=array[b+1+j];
    R[lengthR]=INT_MAX;//哨兵
    
    //按照期望的顺序将L,R合并到array中
    int l=0,r=0;
    for(int k=0;k<lengthL+lengthR;k++)
        if(L[l]<=R[r])
            array[a+k]=L[l++];
        else
            array[a+k]=R[r++]; 
    
    free(L);
    free(R);
}

//上面的合并方式使用INT_MAX作为哨兵，所以要求待排序的数组中的数据不含INT_MAX
//也可以不用哨兵的这种方式，可以检查L或R中的元素有没有完全赋值到原数组array中
//如果一个数组已经完全赋值到原数组中，那么循环就立即停止，然后将另一个数组中剩下的
//元素直接赋值到原数组中即可。

void merge_sort(int *a,int i,int j){
    if(i<j){
        int q=(i+j)/2;
        merge_sort(a,i,q);
        merge_sort(a,q+1,j);
        merge(a,i,q,j);
    }
}

int main (void){
    int a[]={1,2,3,4,5,8,0,1,2,0};
    merge_sort(a,0,9);
    // merge(a,0,2,4);
    for(int i=0;i<10;i++)
        printf("%d ",a[i]);
    return 0;
}
