/**
 * 实现文件
 */
#include <iostream>
#include "LinkedList.h"

using namespace std;
namespace mylinkedlist
{

//LinkedList构造函数
LinkedList::LinkedList()
{
    head = new Node;
    head->next = NULL; //保护指针，防止指向不明变量
    tail = head;
    count = 0;
}

//获取链表长度
int LinkedList::size()
{
    return count;
}

//尾部插入节点
void LinkedList::append(ElementType e)
{
    //开辟内存
    NodePtr ptemp = new Node;
    if (ptemp == NULL)
    {
        cout << "分配内存失败！" << endl;
        exit(1);
    }
    //填充节点
    ptemp->data = e;
    ptemp->next = NULL;
    //连接
    tail->next = ptemp;
    tail = ptemp;
    //更新count
    count++;
}

//头部插入
void LinkedList::push_head(ElementType e)
{
    NodePtr ptemp = new Node;
    if (ptemp == NULL)
    {
        cout << "分配内存失败！" << endl;
        exit(1);
    }
    ptemp->data = e;
    ptemp->next = head->next;
    head->next = ptemp;
    count++;
}

//打印链表
void LinkedList::print()
{
    NodePtr phead = head;
    phead = phead->next;
    while (phead != NULL)
    {
        cout << phead->data << " ";
        phead = phead->next;
    }
    cout << endl;
}

//匹配并删除第一个匹配的节点
void LinkedList::deleteFirst(ElementType e)
{
    NodePtr phead, ptemp;
    phead = head;
    ptemp = phead;
    phead = phead->next;
    while (phead != NULL)
    {
        if (phead->data == e)
        {
            ptemp->next = phead->next;
            delete phead;
            count--;
            break;
        }
        phead = phead->next;
        ptemp = ptemp->next;
    }
}

//匹配并删除所有匹配的节点
void LinkedList::deleteAll(ElementType e)
{
    NodePtr phead, ptemp;
    phead = head;
    ptemp = phead;
    phead = phead->next;
    while (phead != NULL)
    {
        if (phead->data == e)
        {
            ptemp->next = phead->next;
            delete phead;
            count--;
            phead = ptemp->next;
        }
        else
        {
            phead = phead->next;
            ptemp = ptemp->next;
        }
    }
}

//反序
void LinkedList::reverse()
{
    NodePtr p, q,r;
    NodePtr h=new Node;
    p = NULL;
    q = head->next;
    delete head;
    // head = NULL; //旧的头指针是新的尾指针，next需要指向NULL
    while (q)
    {
        r = q->next; //先保留下一个step要处理的指针
        q->next = p; //然后p q交替工作进行反向
        p = q;
        q = r;
    }
    h->next=p;
    
    // tail = head;
    head = h; // 最后q必然指向NULL，所以返回了p作为新的头指针
}

//排序
void LinkedList::sort(char rule)
{
    NodePtr phead, ptemp;
    if (rule == '<')
    {
        for (phead = head->next; phead != NULL; phead = phead->next)
        {
            for (ptemp = phead->next; ptemp != NULL; ptemp = ptemp->next)
            {
                if (phead->data > ptemp->data)
                {
                    ElementType temp = phead->data;
                    phead->data = ptemp->data;
                    ptemp->data = temp;
                }
            }
        }
    }
    else if (rule == '>')
    {
        for (phead = head->next; phead != NULL; phead = phead->next)
        {
            for (ptemp = phead->next; ptemp != NULL; ptemp = ptemp->next)
            {
                if (phead->data < ptemp->data)
                {
                    ElementType temp = phead->data;
                    phead->data = ptemp->data;
                    ptemp->data = temp;
                }
            }
        }
    }
    else
    {
        cout << "请正确指明排序规则,'<'或'>'!";
        exit(1);
    }
}

//在第pos个节点之后插入数据域为e的节点
void LinkedList::insert(int pos, ElementType e)
{
    //首先要找到第pos个节点
    NodePtr ptemp = head;
    ptemp = ptemp->next;
    for (int i = 0; i < pos - 1; i++)
    {
        ptemp = ptemp->next;
    }
    NodePtr ptemp1 = new Node;
    ptemp1->data = e;
    ptemp1->next = ptemp->next;
    ptemp->next = ptemp1;
}
}