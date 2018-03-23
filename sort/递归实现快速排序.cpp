/**
 * 快速排序的递归实现
 */ 
#include <stdio.h>
void quickSort(int*p,int left,int right){
    int i,j;
    int x,y;
    i=left;
    j=right;
    x=p[(left+right)/2];
    do{
        while((p[i]<x)&&(i<right)) i++;
        while((p[j]>x)&&(j>left)) j--;
       
        if(i<=j){
            y=p[i];
            p[i]=p[j];
            p[j]=y;
            i++;
            j--;
        }
    }while(i<=j);

    if(left<j)
    quickSort(p,left,j);
    if(i<right)
    quickSort(p,i,right);
}

int main(void){
    int a[]={1,5,3,0,12,2,5,6,1,8,3,7};
    //排序前
    for(int i=0;i<12;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    quickSort(a,0,11);
    //排序后
    for(int i=0;i<12;i++){
        printf("%d ",a[i]);
    }
}