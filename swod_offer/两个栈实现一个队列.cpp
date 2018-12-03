/*添加的时候一直从stack1中添加
 * 删除的时候，如果stack中有数据则直接取
 * stack2栈顶的元素删除，如果此时stack2为
 * 空则将stack1中的元素取出，然后放到stack2*/

#include <stack>
#include <iostream>
using namespace std;

class MyQueue
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty())
        while(!stack1.empty()){
            /*获取stack1栈顶元素，并将其从栈stack1中删除*/
            int tmp = stack1.top();
            stack1.pop();

            /*添加至stack2中*/
            stack2.push(tmp);
        }

        if(stack2.empty())
            throw "no element in queue";

        int temp = stack2.top();
        stack2.pop();
        return temp;

    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


int main(int argc, char** argv){
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    cout<<queue.pop()<<endl;
    cout<<queue.pop()<<endl;
    queue.push(4);
    cout<<queue.pop()<<endl;
    queue.push(5);
    cout<<queue.pop()<<endl;
    cout<<queue.pop()<<endl;
    return 0;

}