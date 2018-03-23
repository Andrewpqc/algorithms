//直接插入排序　从小到大
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int main(void){
   int a[9]={100,5,2,3,4,65,8,9,1};
   int length=9;
   for(int i=1;i<length;i++)
   {
       //变量temp用于保存取到的数据，防止后面的移动而被覆盖
       int temp=a[i];//待插入的数据(无序区左边的第一个元素)
       int j=i-1;//有序取右边的第一个元素
       if(a[j]>temp){
           //如果a[j]<=temp则说明temp插入的位置就是当前所在的位置，直接取下一个数，进入下一轮循环.
           //这里a[j]>temp,说明temp插入的位置不在当前位置，而在更低位，下面就是要寻找这样的位置
           do{
               a[j+1]=a[j];
               j--;
           }while(a[j]>temp);
           //找到了temp该插入的位置，插入temp
           a[j+1]=temp;
       }
   }

    //打印输出
    for(int k=0;k<9;k++){
        cout<<a[k]<<" ";
    }
    cout<<endl;
    return 0;
}
/**
 * Insertion Sort
 * 将数据分为有序区和无序区，依次从无序区中取数据，插入到有序区中，每次操作过后有序区的大小加一，无序区的大小减一，
 * 当无序区大小为0时，排序也就完成了。在把取到的数据插入有序区中的操作可以充分利用有序区数据已经有序的特点，从而实现
 * 优化。
 *
 */
