#include <iostream>

using namespace std;

int maxSumOfSubArray(int *array, int length) {
    int currentSum = 0;
    int greatestSum = 0;
    for (int i = 0; i < length; ++i) {
        if (currentSum <= 0) currentSum = array[i];
        else currentSum += array[i];

        if (currentSum > greatestSum) greatestSum = currentSum;
    }

    return greatestSum;
}

/*连续子数组的最大和*/
int main(int argc, char **argv) {
    int array[] = {1, 2, 3, -10, 6};
    cout << maxSumOfSubArray(array, 5) << endl;
    return 0;
}