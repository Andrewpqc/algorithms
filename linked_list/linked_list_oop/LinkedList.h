/**
 * 接口文件
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;
typedef int ElementType;

namespace mylinkedlist
{

typedef struct Node
{
    struct Node *next;
    ElementType data;
} Node, *NodePtr;

class LinkedList;
//定义这个类
class LinkedList
{
  public:
    //构造函数
    LinkedList();

    //获取链表长度
    int size();

    //打印链表
    void print();

    //尾部增加节点
    void append(ElementType e);

    //头部插入节点
    void push_head(ElementType e);

    //释放整个链表
    void destroy();

    //匹配并删除第一个匹配的节点
    void deleteFirst(ElementType e);

    //匹配并删除所有的匹配的节点
    void deleteAll(ElementType e);

    //反序
    void reverse();

    //排序,默认从小到大排序
    void sort(char rule = '<');

    //在指定位置插入指定节点
    //在第pos个节点之后插入数据域为e的节点
    void insert(int pos, ElementType e);

    //将两个已经按相同规则排序的链表合并并且按指定规则排序
    void merge(LinkedList &, char originalrule, char rule = '<');

  private:
    NodePtr head;
    NodePtr tail;
    int count;
};
}
#endif
