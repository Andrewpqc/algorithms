#include <iostream>
#include <vector>

using namespace std;

int maxSumOfSubArray(int *array, int length) {
    int begin_index = 0;
    int end_index = 0;
    int result_begin_index = 0;
    int result_end_index = 0;
    int currentSum = 0;
    int greatestSum = 0;
    for (int i = 0; i < length; ++i) {
        if (currentSum <= 0) {
            currentSum = array[i];
            begin_index = i;
            end_index = i;
        } else {
            currentSum += array[i];
            ++end_index;
        }

        if (currentSum > greatestSum) {
            greatestSum = currentSum;
            result_begin_index = begin_index;
            result_end_index = end_index;
        }

    }
    cout << result_begin_index << " " << result_end_index << endl;
    return greatestSum;
}

/*连续子数组的最大和*/
int main(int argc, char **argv) {
    int array[] = {1, 2, 3, -10, 6};
    cout << maxSumOfSubArray(array, 5) << endl;
    return 0;
}