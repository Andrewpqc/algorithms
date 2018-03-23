/**
 * 非递归实现最大子数组问题
 * 从左向右扫描数组，记录a[0...i]的最大子数组
 * 那么a[0...i+1]的最大子数组要么是a[0...i]的最大子数组
 * 要么是a[j...i+1](0<=j<=i)
 **/ 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct RetContent{
    int left;
    int right;
    int sum;
}R;
R find_max_subarray(int * a,size_t size){
    int current_sum=a[0];
    int max_l=0;
    int max_r=0;
    //从左至右一个一个考察
    for(int i=1;i<=size;i++){
        int next_sum=INT_MIN; 
        int sum=0;
        int l=0;
        for(int j=i;j>=0;j--){
            sum+=a[j];
            if(sum>next_sum){
                next_sum=sum;
                l=j;
            }
        }
        if(next_sum>current_sum){
            current_sum=next_sum;
            max_l=l;
            max_r=i;
        }
    }
    R r;
    r.left=max_l;
    r.right=max_r;
    r.sum=current_sum;
    return r;
}
int main (void){
    int a[5]={1, 2 ,-3, -5, 9};
    R r=find_max_subarray(a,4);
    printf("%d %d %d",r.left,r.right,r.sum);
    return 0;
}