#include <iostream>

using namespace std;

/*这种方法是有多少个位就会比较多少次*/
int numberOfBit1_first(int a) {
    unsigned int flag = 1;
    int count = 0;
    while (flag) {
        if (a & flag)
            ++count;
        flag = flag << 1;
    }
    return count;
}

/*下面这种方法是有多少个1就比较多少次*/
int numberOfBit1_second(int a) {
    int count = 0;
    while (a) {
        ++count;
        a = (a - 1) & a;
    }
    return count;
}

int main(int argc, char **argv) {
    cout << numberOfBit1_first(9) << endl; //1001 --->2，循环4次
    cout << numberOfBit1_second(9) << endl; //1001 ---->2, 仅仅循环两次
}