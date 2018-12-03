#include <string>
#include <iostream>
#include <exception>
#include <cstring>

using namespace std;


class Solution {
public:
    /*str字符串指针， length为空余空间大小*/
    void replaceSpace(char *str, int length) {
        if (str == nullptr)
            throw "invalid parameter";

        int space_count = 0;

        size_t origin_length = strlen(str);

        for (size_t i = 0; i < origin_length; ++i) {
            if (str[i] == ' ') ++space_count;
        }

        size_t new_length = origin_length + 2 * space_count;

        if (new_length + 1 > length)
            throw "lack of avaliable space";

        int origin_index = (int) origin_length - 1;
        int new_index = (int) new_length - 1;

        while (space_count != 0) {
            if (str[origin_index] != ' ')
                str[new_index--] = str[origin_index--];
            else {
                str[new_index--] = '0';
                str[new_index--] = '2';
                str[new_index--] = '%';
                --space_count; //成功替换完了一个空格
                --origin_index;
            }

        }

        /*给字符串末尾添加 '\0'*/
        str[new_length] = '\0';
    }
};

int main(int argc, char **argv) {
    Solution solution;
    char *s1 = "hello, world";
    solution.replaceSpace(s1, 50);
    cout << s1 << endl;
}