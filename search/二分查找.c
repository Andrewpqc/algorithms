#include <stdio.h>
#include <stdlib.h>
int find(int * a, int begin, int end, int target){
    if(begin<end){
        int middle=(begin+end)/2+1;
        if(target==a[middle])
            return middle;
        else if(target > a[middle])
            find(a,middle,end,target);
        else if(target<a[middle])
            find(a,begin,middle,target); 
    }
}
int main (void){
    int a[]={1,2,3,4,5,6,7,8,9};
    int b=find(a,0,8,5);
    printf("%d",b);

    return 0;
}