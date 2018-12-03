/*二维数组中的查找*/

/*这里要注意一个问题
 * size_t 为unsiged long类型，当size_t a = 0的时候
 *a--得到的是一个很大的数而不是-1*/

#include <iostream>
#include <vector>
#include <cassert>


using namespace std;

class Solution {
public:
    bool Find(int target, const vector<vector<int> > &array) {
        /*获取二维数组的行、列*/
        int col = array.size();
        if (col < 1)
            return false;
        int row = array.at(0).size();
        if (row < 1)
            return false;

        int current_col = 0;
        int current_row = row - 1;
        while ((current_col <= (col - 1)) && (current_row >= 0)) {

            int current_val = array[current_col][current_row];

            if (target == current_val) return true;
            else if (target > current_val) ++current_col;
            else --current_row;
        }

        return false;
    }
};

int main(int argc, char **argv) {
    vector<vector<int> > v1{{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}};

    vector<vector<int> > v2{{}};

    vector<vector<int> > v3{{1, 2, 3}};

    vector<vector<int> > v4{{1, 2, 8,  9},
                            {2, 4, 9,  12},
                            {4, 7, 10, 13},
                            {6, 8, 11, 15}};
    Solution solution;
    cout << solution.Find(8, v1) << " " << solution.Find(22, v1) << endl;

    cout << solution.Find(1, v2) << endl;

    cout << solution.Find(1, v3) << " " << solution.Find(5, v3) << endl;

    cout << solution.Find(0, v4) << endl;
}