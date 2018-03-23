// #include <iostream>
// using namespace std;
// void BubbleSort(int * R)  
//  { //R（l..n)是待排序的文件，采用自下向上扫描，对R做冒泡排序  
//    int i，j;   
//    for(i=1;i<10;i++){ //最多做n-1趟排序  
//      bool flag=false； //本趟排序开始前，交换标志应为假  
//      for(j=10-1;j>=i；j--) //对当前无序区R[i..n]自下向上扫描  
//       if(R[j+1]<R[j]){//交换记录  
//         int temp=R[j+1]； //R[0]不是哨兵，仅做暂存单元  
//         R[j+1]=R[j]；  
//         R[j]=temp；  
//         flag=true； //发生了交换，故将交换标志置为真  
//        }  
//      if(!exchange) //本趟排序未发生交换，提前终止算法  
//            return；  
//    } //endfor(外循环)  
//   } //BubbleSort  

//   int main(void){

//     int R[10]={1,5,3,4,6,8,2,7,9,12};
//     BubbleSort(R);
//     for(int k=0;k<10;k++){
//         cout<<a[k]<<" ";
//     }
//     cout<<endl;
//       return 0;
//   }

#include <iostream>
using namespace std;
int main(void){
    int a[10]={1,5,2,3,4,0,5,9,6,3};
    int length=10;
    //外循环控制扫描的次数，只需要扫描n-1次
    for(int i=1;i<length;i++){
        bool flag=false;
        for(int j=length-1;j>=i;j--){//从底部扫描起，有不符合规则的则交换
            if(a[j]<a[j-1]){
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                flag=true;
            }
        }
        if(!flag){
            //说明此时数据已经有序，不必继续循环了。
            break;
        }
    }

    //打印
    for(int k=0;k<length;k++){
        cout<<a[k]<<" ";
    }
    cout<<endl;
    return 0;
}