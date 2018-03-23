/**
 * 接口文件
 */ 

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#define INIT_CAPACITY 10
#define DELTA_CAPACITY 1
using namespace std;
typedef int ElementType;



namespace mydynamicarray{
    class DynamicArray;
    //定义这个类
    class DynamicArray{
    public:
        //构造函数
        DynamicArray();

        //获取长度
        int getSize();

        //获取容量
        int getCapacity();

        //最大值的索引
        int max();

        //最小值的索引
        int min();

        //打印输出
        void print();

        //在末尾追加数据
        void append(ElementType e);

        //在指定下标的前面插入指定的数据
        void insert(int pos,ElementType e);

        //移除指定下标的数据
        void remove(int pos);

        //销毁
        void todestroy();

        //按照指定规则排序，默认从小到大
        void sort(char rule='<');

        //合并两个动态数组，并且按照规则排序
        void mergeAndsort(DynamicArray&,char rule);

        //对两个已经具有相同顺序的动态数组进行合并并且排序
        void mergeAndsort_for_sorted(DynamicArray&,DynamicArray&,char originrule,char rule='<');
    
    private:
        void dealOverflow();//重新分配内存
        ElementType* elems;
        int size;
        int capacity;
    };//注意类的定义的末尾需要有分号
}
#endif