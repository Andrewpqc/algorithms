/**
 * 单链表常用操作
 */ 
#include <iostream>
using namespace std;

//定义结构体
typedef struct Node{
    int data;
    struct Node* next;    
}Node,*NodePtr;

//创建链表
NodePtr createList(void){
    NodePtr headPtr=new Node;
    headPtr->next=NULL;
    return headPtr;
}

//计算节点的长度(不包含头结点),也可以判断链表是否为空
int listSize(NodePtr phead){
    int i=0;
    //跳过头结点
    phead=phead->next;
    while(phead!=NULL){
        i+=1;
        phead=phead->next;
    }
    return i;
}

void printList(NodePtr phead){
    phead=phead->next;
    cout<<"打印所有节点：";
    while(phead!=NULL){
        cout<<phead->data<<" ";
        phead=phead->next;
    }
    cout<<endl;
}

//增加节点
void addNode(NodePtr phead){
    int a=0;
    cout<<"输入你要增加的节点数："<<endl;
    cin>>a;
    for (int i=0;i<a;i++){
        NodePtr ptemp=new Node;
        ptemp->next=NULL;
        cout<<"输入第"<<i+1<<"个节点的数据值"<<endl;
        cin>>ptemp->data;
        phead->next=ptemp;
        phead=phead->next;
    } 
}

//删除第一个匹配到的节点（通过测试）
void deleteOneNode(NodePtr phead,int _data){
    NodePtr ptemp;
    ptemp=phead;
    phead=phead->next;
    //空链表的情况
    if(phead==NULL){
        cout<<"链表为空！"<<endl;
    }
    while(phead!=NULL){
        //找到了
        if(phead->data==_data){
            ptemp->next=phead->next;
            delete phead;
            break;
        }
        //没找到
        phead=phead->next;
        ptemp=ptemp->next;
    }
} 

//现在还是只可以删除第一个匹配的节点？？(未通过测试)
void deleteAllNode(NodePtr phead,int _data){
    NodePtr ptemp;
    ptemp=phead;
    phead=phead->next;
    //空链表的情况
    if(phead==NULL){
        cout<<"链表为空！"<<endl;
        return;
    }
    while(phead!=NULL){
        if(phead->data==_data){
            ptemp->next=phead->next;
            delete phead;
            phead=ptemp->next;
        }else{
        phead=phead->next;
        ptemp=ptemp->next;
        }
    }
}

//在头部插入节点（未通过测试）
void insertAtHead(NodePtr phead){
    NodePtr ptemp=new Node;
    cout<<"输入在头部插入的数据值"<<endl;
    cin>>ptemp->data;
    ptemp->next=phead->next;
    phead->next=ptemp;
}

//通过测试
void insertAtTail(NodePtr phead){
    //先创建需要插入的节点
    NodePtr pinsert=new Node;
    cout<<"输入在尾部插入的数据"<<endl;
    cin>>pinsert->data;
    pinsert->next=NULL;

    NodePtr ptemp=phead;
    phead=phead->next;
    while(phead!=NULL){
        phead=phead->next;
        ptemp=ptemp->next;
    }
    ptemp->next=pinsert;
}

//递归释放整个单链表
void destoryList(NodePtr phead){
    if(phead->next!=NULL){
        destoryList(phead->next);
    }
    delete phead; 
}

int main(void){
    //创建头结点
    NodePtr phead=createList();

    //测试增加节点
    addNode(phead);
    printList(phead);
    cout<<"节点数量：";
    cout<<listSize(phead)<<endl;

    // //测试从尾部插入一个节点
    insertAtTail(phead);
    cout<<"从尾部插入节点后："<<endl;
    printList(phead);
    cout<<"节点数量：";
    cout<<listSize(phead)<<endl;

    insertAtHead(phead);
    cout<<"从头插入节点后："<<endl;
    printList(phead);
    cout<<"节点数量：";
    cout<<listSize(phead)<<endl;
    //测试删除第一个匹配的节点
    int a;
    cout<<"请输入你要删除的元素的值(只删除第一个匹配的值)："<<endl;
    cin>>a;
    deleteOneNode(phead,a);
    cout<<"删除第一个"<<a<<"后："<<endl;
    printList(phead);
    cout<<"节点数量：";
    cout<<listSize(phead)<<endl;

    //测试删除所有匹配的节点
    int b;
    cout<<"请输入你要删除的元素的值(将删除所有匹配的值)："<<endl;
    cin>>b;
    deleteAllNode(phead,b);
    cout<<"删除所有的"<<b<<"后："<<endl;
    printList(phead);
    cout<<"节点数量：";
    cout<<listSize(phead)<<endl;

    destoryList(phead);
    return 0;
}
