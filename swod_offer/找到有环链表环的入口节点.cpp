#include <iostream>
#include <cassert>

typedef struct ListNode {
    int val;
    ListNode *next;
} ListNode, *ListNodePtr;


bool hasCircle(ListNodePtr pHead,ListNodePtr* circleNode) {

    /*空链表或仅一个节点的链表肯定没有环*/
    if (pHead == nullptr || pHead->next == nullptr)
        return false;

    ListNodePtr pFast = pHead;
    ListNodePtr pSlow = pHead;
    while (pFast != nullptr && pFast->next != nullptr) {

        pFast = pFast->next->next;
        pSlow = pSlow->next;

        if (pFast == pSlow) {
            *circleNode=pFast;
            return true;
        }

    }
    return false;
}


ListNodePtr findEntryPointOfTheCircle(ListNodePtr pHead){
    ListNodePtr inCircleNode= nullptr;
    bool has_circle =hasCircle(pHead,&inCircleNode);

    if(!has_circle) return nullptr;

    ListNodePtr pFast2=pHead;
    ListNodePtr pSlow = inCircleNode;

    /*快指针回到起点，慢指针在开始处
     * 这一次快指针和慢指针都是每次走一步
     * 当他们再次相遇的时候，相遇点就是环的入口*/
    while (pFast2!=pSlow){
        pFast2=pFast2->next;
        pSlow=pSlow->next;
    }

    return pFast2;
}


int main(int argc, char **argv) {



    ListNode node1{.val=12};
    ListNode node2{.val=13};
    ListNode node3{.val=13};
    ListNode node4{.val=13};
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node2;


    ListNode node5{.val=12};
    ListNode node6{.val=13};
    ListNode node7{.val=13};
    ListNode node8{.val=13};
    node5.next = &node6;
    node6.next = &node7;
    node7.next = &node8;
    node8.next = &node5;

    ListNode node9{.val=12};
    ListNode node10{.val=13};
    node9.next = &node10;
    node10.next = &node9;


    assert(findEntryPointOfTheCircle(&node1) == &node2);
    assert(findEntryPointOfTheCircle(&node5) == &node5);
    assert(findEntryPointOfTheCircle(&node9) == &node9);

    return 0;
}


