/*旋转数组的最小值*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int> &rotateArray, int low, int high) {
        int minNum = rotateArray[low];
        for (int i = low + 1; i <= high; ++i) {
            if (rotateArray[i] < minNum) minNum = rotateArray[i];
        }

        return minNum;
    }

    int minNumberInRotateArray(vector<int> &rotateArray) {
        int low = 0;
        int high = (int) rotateArray.size() - 1;
        int minIndex = low;
        while (low < high) {
            if (low + 1 == high) {
                minIndex = high;
                break;
            }

            int mid = (low + high) >> 1;
            if (rotateArray[low] == rotateArray[mid] &&
                rotateArray[mid] == rotateArray[high]) {
                return search(rotateArray, low, high);
            }

            if (rotateArray[mid] >= rotateArray[low]) low = mid;
            else high = mid;
        }

        return rotateArray[minIndex];
    }
};


int main(int argc, char **argv) {
    Solution solution;
    vector<int> array = {3, 4, 5, 1, 2};
    vector<int> array2 = {1, 1, 1, 1, 1};
    vector<int> array3 = {1, 1, 1, 0, 1};
    vector<int> array4 = {1, 0, 1, 1, 1};

    cout << solution.minNumberInRotateArray(array) << endl;
    cout << solution.minNumberInRotateArray(array2) << endl;
    cout << solution.minNumberInRotateArray(array3) << endl;
    cout << solution.minNumberInRotateArray(array4) << endl;

    return 0;
}