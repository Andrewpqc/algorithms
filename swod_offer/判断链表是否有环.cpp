#include <iostream>
#include <cassert>

typedef struct ListNode {
    int val;
    ListNode *next;
} ListNode, *ListNodePtr;


bool hasCircle(ListNodePtr pHead) {

    /*空链表或仅一个节点的链表肯定没有环*/
    if (pHead == nullptr || pHead->next == nullptr)
        return false;

    ListNodePtr pFast = pHead;
    ListNodePtr pSlow = pHead;
    while (pFast != nullptr && pFast->next != nullptr) {

        pFast = pFast->next->next;
        pSlow = pSlow->next;

        if (pFast == pSlow) return true;

    }
    return false;
}


int main(int argc, char **argv) {

    ListNode single_node{.val=5, .next=nullptr};

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
    node8.next = &node6;

    ListNode node9{.val=12};
    ListNode node10{.val=13};
    node9.next = &node10;
    node10.next = &node9;


    assert(hasCircle(nullptr) == false);
    assert(hasCircle(&single_node) == false);
    assert(hasCircle(&node1) == true);
    assert(hasCircle(&node5) == true);
    assert(hasCircle(&node9) == true);

    return 0;
}




