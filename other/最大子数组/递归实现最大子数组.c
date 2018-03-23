/**
 * 递归求最大子数组，算法真的好神奇啊
 **/ 

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
typedef struct RetContent{
    int left;
    int right;
    int sum;
}R;
//寻找跨越中点的最最大子数组
R find_crossing_subarray(int *a,int low,int middle,int high){
    int left_sum=INT_MIN,right_sum=INT_MIN;//存储最前子数组的和
    int left_max=-1,right_max=-1;//存储当前找到的最大子数组的下标
    int sum_l=0,sum_r=0;
    for(int i=middle;i>=low;i--){
        sum_l+=a[i];
        if(sum_l>left_sum){
            left_sum=sum_l;
            left_max=i;
        }
    }
    for(int j=middle+1;j<=high;j++){
        sum_r+=a[j];
        if(sum_l>right_sum){
            right_sum=sum_r;
            right_max=j;
        }
    }
    R r;
    r.left=left_max;
    r.right=right_max;
    r.sum=left_sum+right_sum;
    return r;
}


R find_maximum_subarray(int * a,int low,int high){
    if(low==high){
        R r;
        r.left=low;
        r.right=high;
        r.sum=a[low];
        return r;
    }
    else{
        int mid=(low+high)/2;
        R r1=find_maximum_subarray(a,low,mid);
        R r2=find_maximum_subarray(a,mid+1,high);
        R r3=find_crossing_subarray(a,low,mid,high);

        if(r1.sum>=r2.sum && r1.sum>=r3.sum)
            return r1;
        else if(r2.sum>=r1.sum && r2.sum>= r3.sum)
            return r2;
        else
            return r3;
    }
}

int main (void){
    int a[]={-1,-1,-1,-2,-8,-5,-2,-3,-9,0,-3,-3,-5};
    R result=find_maximum_subarray(a,0,11);
    printf("%d %d %d",result.left,result.right,result.sum);
    return 0;
}