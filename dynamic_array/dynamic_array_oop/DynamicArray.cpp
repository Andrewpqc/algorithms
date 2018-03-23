/**
 * 实现文件
 */ 
#include <iostream>
#include <cstdlib>
#include "DynamicArray.h"

using namespace std;
namespace mydynamicarray{
    //构造函数
    DynamicArray::DynamicArray(){
        elems=new ElementType[INIT_CAPACITY];
        size=0;
        capacity=INIT_CAPACITY;
    }
   
    //获取长度
    int DynamicArray::getSize(){
        return size;
    }

    //获取容量
    int DynamicArray::getCapacity(){
        return capacity;
    }

    //最大值
    int DynamicArray::max(){
        int result=0;
        for(int i=0;i<size-1;i++){
            result=(elems[i]>elems[i+1])?i:i+1;
        }
        return result;
    }

    //最小值
    int DynamicArray::min(){
        int result=0;
        for(int i=0;i<size-1;i++){
            result=(elems[i]<elems[i+1])?i:i+1;
        }
        return result;
    }

    //打印
    void DynamicArray::print(){
        for(int i=0;i<size;i++){
            cout<<elems[i]<<" ";
        }
        cout<<endl;
    }

    //处理重新分配问题
    void DynamicArray::dealOverflow(){
        if(size>=capacity){
            cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
            ElementType* newbase=(ElementType*)realloc(elems,size+DELTA_CAPACITY);
            if(newbase==NULL){
                cout<<"重新分配内存失败！"<<endl;
                return;
            }
            elems=newbase;
            capacity+=DELTA_CAPACITY;
        }
    }

    //尾部追加
    void DynamicArray::append(ElementType e){
        dealOverflow();
        elems[size]=e;
        size++;
        printf("<<<<");
    }

    //在指定下表位置插入
    void DynamicArray::insert(int pos,ElementType e){
        dealOverflow();
        if(pos<0||pos>size){
            cout<<"指定的位置不合法！"<<endl;
            return;
        }
        int i;
        for(i=size;i>pos;i--){
            elems[i]=elems[i-1];
        }
        elems[i]=e;
        size++;
    }

    //删除指定下表的元素
    void DynamicArray::remove(int pos){
        if(pos<0||pos>size){
            cout<<"指定的位置不合法！"<<endl;
            return;
        }

        int i;
        for(i=pos;i<size;i++){
            elems[i]=elems[i+1];
        }
        size--;
    }

    //销毁
    void DynamicArray::todestroy(){
        delete [] elems;
        size=0;
        capacity=0;
    }

    void DynamicArray::sort(char rule){
        if(rule=='<'){//从小到大排序
            for(int i=0;i<size;i++){
                for(int j=i+1;j<size;j++){
                    if(elems[i]>elems[j]){
                        int temp=elems[i];
                        elems[i]=elems[j];
                        elems[j]=temp;
                    }
                }
            }
        }
        else if(rule=='>'){//从大到小排序
            for(int i=0;i<size;i++){
                for(int j=i+1;j<size;j++){
                    if(elems[i]<elems[j]){
                        int temp=elems[i];
                        elems[i]=elems[j];
                        elems[j]=temp;
                    }
                }
            }
        }
        else{//rule参数输入错误
            cout<<"请输入正确的排序规则('<' or '>')!!!"<<endl;
            return;
        }
    }

    void DynamicArray::mergeAndsort(DynamicArray& dyArray,char rule='<'){
        for(int i=0;i<dyArray.size;i++){
            append(dyArray.elems[i]);
        }
        //销毁DA2,注意不能够两次释放，如果这里释放了，那么在其他的地方
        //不能再次释放
        // dyArray.todestroy();
        //排序
        sort(rule);
    }

    //对两个已经有序的动态数组进行合并排序
    void DynamicArray::mergeAndsort_for_sorted(DynamicArray& DA2,DynamicArray& DA3,char originrule,char rule){
        if(originrule=='<'&&rule=='<'){
                int i=0,j=0;
                while(i!=size&&j!=DA2.size){
                    if(elems[i]<DA2.elems[j]){
                        DA3.append(elems[i]);
                        i++;
                    }else if(elems[i]==DA2.elems[j]) {
                        //防止循环的最后一个相同的时候漏掉一个
                        DA3.append(elems[i]);
                        i++;
                        DA3.append(DA2.elems[j]);
                        j++;
                    }else{
                        DA3.append(DA2.elems[j]);
                        j++;
                    }
                }
                if(size==i){
                    while(j<DA2.size){
                       DA3.append(DA2.elems[j]);
                        j++;
                    }
                    }
                else if(DA2.size==j){
                    while(i<size){
                       DA3.append(elems[i]);
                        i++;
                    }
                    }
        }
        else if(originrule=='>'&&rule=='>'){
           int i=0,j=0;
           while(i!=size&&j!=DA2.size){
               if(elems[i]<DA2.elems[j]){
                   DA3.append(DA2.elems[j]);
                   j++;
               }else if(elems[i]==DA2.elems[j]) {
                   //防止循环的最后一个相同的时候漏掉一个
                   DA3.append(elems[i]);
                   i++;
                   DA3.append(DA2.elems[j]);
                   j++;
               }else{
                   DA3.append(elems[i]);
                   i++;
               }
           }
           if(size==i){
               while(j<DA2.size){
                  DA3.append(DA2.elems[j]);
                   j++;
               }
               }
           else if(DA2.size==j){
               while(i<size){
                  DA3.append(elems[i]);
                   i++;
               }
               }
        }
        else if(originrule=='<'&&rule=='>'){
           int i=size-1,j=DA2.size-1;
           while(i!=-1&&j!=-1){
               if(elems[i]<DA2.elems[j]){
                   DA3.append(DA2.elems[j]);
                   j--;
               }else if(elems[i]==DA2.elems[j]) {
                   //防止循环的最后一个相同的时候漏掉一个
                   DA3.append(elems[i]);
                   i--;
                   DA3.append(DA2.elems[j]);
                   j--;
               }else{
                   DA3.append(elems[i]);
                   i--;
               }
           }
           if(-1==i){
               while(j!=-1){
                  DA3.append(DA2.elems[j]);
                   j--;
               }
               }
           else if(-1==j){
               while(i!=-1){
                  DA3.append(elems[i]);
                   i--;
               }
               }
        }
        else if(originrule=='>'&&rule=='<'){
           int i=size-1,j=DA2.size-1;
           while(i!=-1&&j!=-1){
               if(elems[i]<DA2.elems[j]){
                   DA3.append(elems[i]);
                   i--;
               }else if(elems[i]==DA2.elems[j]) {
                   //防止循环的最后一个相同的时候漏掉一个
                   DA3.append(elems[i]);
                   i--;
                   DA3.append(DA2.elems[j]);
                   j--;
               }else{
                   DA3.append(DA2.elems[j]);
                   j--;
               }
           }
           if(-1==i){
               while(j!=-1){
                  DA3.append(DA2.elems[j]);
                   j--;
               }
               }
           else if(-1==j){
               while(i!=-1){
                  DA3.append(elems[i]);
                   i--;
               }
               }
        }
        else{
            printf("原始规则或指定的规则不正确");
            exit(1);
        }
    }

}