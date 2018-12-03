/*添加元素的时候，如果两个队列当前都为空
 * 则随便选择一个队列添加
 * 如果当前栈中有元素，则将新数据添加到
 * 非空对列中
 *
 * 删除元素时,将非空队列的元素逐个取出，然后放到
 * 另一个队列里面，直到取到倒数第二个元素，将最
 * 后一个取出并返回*/

#include <queue>
#include <iostream>

using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int data) {
        if (q1.empty()) q2.push(data);
        else q1.push(data);
    }

    int pop() {

        if (q1.empty()) {
            while (q2.size() > 1) {
                int tmp_val = q2.front();
                q2.pop();
                q1.push(tmp_val);
            }

            int data_to_pop = q2.front();
            q2.pop();
            return data_to_pop;
        } else if (q2.empty()) {
            while (q1.size() > 1) {
                int tmp_val = q1.front();
                q1.pop();
                q2.push(tmp_val);
            }

            int data_to_pop = q1.front();
            q1.pop();
            return data_to_pop;
        } else {
            /*两个队列都为空，此时表明没有数据*/
            throw "no element in stack";
        }
    }
};


int main(int argc, char **argv) {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.pop() << endl;
    stack.push(4);
    stack.push(5);
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
}