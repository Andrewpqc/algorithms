/**
 * 测试文件
 */ 

#include <iostream>
#include "DynamicArray.h"
using namespace std;
using namespace mydynamicarray;
int main() {
   DynamicArray array1=DynamicArray();
   for(int i=0;i<12;i++){
       array1.append(i);
   }
   array1.print();
//    array1.append(1);
//    array1.append(3);
//    array1.append(2);
//    for(int i=0;i<120;i++){
//        array1.append(i);
//    }
   
//    array1.print();
//    array1.insert(0,100);
//    array1.insert(2,200);
//    array1.print();
//    for(int i=0;i<10;i++){
//        array1.append(i);
//    }
//    array1.print();
//    array1.sort('>');
//    array1.print();
//    array1.sort();
//    array1.print();
//    DynamicArray array2=DynamicArray();
//    array2.append(1000);#include <iostream>
using namespace std;
int main(void){
    char a[2]={'a','b'};
    printf(a[3]);




    return 0;
}
//    array2.append(3000);
//    array2.append(2000);
//    array2.append(250);
//    array2.append(9000);
//    array2.sort();
//    cout<<array2.getSize()<<"||||||||||||"<<array2.getCapacity()<<endl;
//    array2.print();
//    array1.mergeAndsort(array2,'<');
//    array1.print();
//    DynamicArray array3=DynamicArray();
//    array1.mergeAndsort_for_sorted(array2,array3,'<');
//    array3.print();
//    cout<<array3.max()<<endl;
//    cout<<array3.min()<<endl;




//    array1.todestroy();
//    array2.todestroy();
//    array3.todestroy();
   return 0;
}