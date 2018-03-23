/**
 *Shell Sort 
 * 
 **/
#include<iostream>
using namespace std;
void ShellPass(int* R,int d)  
 {//希尔排序中的一趟排序，d为当前增量  
   for(int i= d+1;i<10;i++)
   { //将R[d+1．．n]分别插入各组当前的有序区 
      int temp=R[i];
      int j=i-d;   
      if(temp<R[j]){
      do {//查找R[i]的插入位置  
          R[j+d]=R[j]; //后移记录  
          j=j-d; //查找前一记录  
       }while(j>0&&temp<R[j]); 
       R[j+d]=temp; //插入R[i]到正确的位置上  
     } //endif  
 } //ShellPass  
 }
void  ShellSort(int* R)  
 {  
  int increment=8;//增量初值，不妨设n>0  
  do {  
        increment=increment/3+1; //求下一增量  
        ShellPass(R,increment); //一趟增量为increment的Shell插入排序  
     }while(increment>1);  
  } //ShellSort  

int main(void){
    int R[]={100,101,3,4,6,8,9,2,1,10};
    ShellSort(R);
    for(int i=0;i<10;i++){
        cout<<R[i]<<" ";
    }
    cout<<endl;
    return 0;
}


/**
 * https://yuyilei.github.io/2017/10/06/sort/#more
 * http://wiki.jikexueyuan.com/project/data-structure-sorting/hill-sorting.html
 * http://bubkoo.com/2014/01/15/sort-algorithm/shell-sort/
 * 
 * 
 * 
 * 
 **/ 