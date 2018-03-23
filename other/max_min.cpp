#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct node{
    int max;
    int min;
}M;

//同时找出一个序列中的最大值和最小值，先取序列中的两个数比较
//大的数如果比max大，则替换max,小的数如果比min小则替换min
//这里要注意的就是当序列的元素个数为奇数时，最后一个元素要
//单独与max,min相比较
//这种方式比较的次数为3(n/2)


//我这里处理奇数和偶数的方式不够优雅
//如果size为奇数时，应该将max=min=a[0],然后成对的处理剩下的数据
//如果size为偶数时，应该比较a[0]和a[1],然后根据a[0],a[1]设置max和min,从而也可以成对的处理剩下的数据
M& max_and_min(int *a,size_t size){
    static M m;
    if(size<1){
        puts("size can't smaller than 1");
        exit(EXIT_FAILURE);
    }
    else if(size==1){
        m.max=m.min=a[0];
    }
    else{
       if(a[0]>a[1]){
           m.min=a[1];
           m.max=a[0];
       }else{
           m.min=a[0];
           m.max=a[1];
       }
        int i;
        for(i=2;i+1<size;i+=2){//两个两个的比较
            if(a[i]>a[i+1]){
                if(a[i]>m.max){
                    m.max=a[i];
                }
                if(a[i+1]<m.min){
                    m.min=a[i+1];
                }
            }
            else{
                if(a[i+1]>m.max){
                    m.max=a[i+1];
                }
                if(a[i]<m.min){
                    m.min=a[i];
                }
            }
        }

        //结束时如果i+1==size，表明最后剩下一个数
        if(i==size-1){
            m.max=(a[i]>m.max)?a[i]:m.max;
            m.min=(a[i]<m.min)?a[i]:m.min;
        }

    }
    return m;
}
int main (void){

    int a[]={1,5,5,6,3,0,10};
    M& m=max_and_min(a,7);
    cout<<m.max<<" "<<m.min<<endl;
    return 0;
}