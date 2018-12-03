struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
};

#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result_vector {};

        if(head==nullptr)
            return result_vector;

        stack<int> stack1;
        ListNode * temp = head;
        while (temp->next!= nullptr){
            stack1.push(temp->val);
            temp= temp->next;
        }

        while (!stack1.empty()){
            //获取栈顶元素并将其从栈中删除
            int tmp_val = stack1.top();
            stack1.pop();

            result_vector.push_back(tmp_val);
        }

        return result_vector;

    }
};