#include <iostream>
#include "LinkedList.h"
using namespace mylinkedlist;
int main(void){
    LinkedList l1=LinkedList();
    l1.append(1);
    l1.append(1);
    l1.append(3);
    l1.append(2);
    l1.append(2);
    l1.append(5);
    l1.append(12);
    l1.append(3);
    // l1.insert(2,100);
    l1.print();
    l1.reverse();
    l1.print();
    l1.reverse();
    l1.print();
    l1.sort('<');
    cout<<l1.size()<<endl;
    l1.print();
    l1.reverse();
    l1.print();
    l1.deleteFirst(1);
    cout<<l1.size()<<endl;
    l1.print();
    l1.deleteAll(2);
   
    cout<<l1.size()<<endl;
    l1.print();
    l1.sort('<');
    l1.print();
    
    return 0;
}