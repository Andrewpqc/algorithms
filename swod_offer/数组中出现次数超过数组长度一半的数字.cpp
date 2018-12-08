#include <iostream>

using namespace std;

/*挖坑填坑*/
int partition(int *array, int low, int high) {
    int i = low;
    int j = high;
    int povit = array[low];

    while (i < j) {
        while (i < j && array[j] >= povit) --j;
        if (i < j) {
            array[i] = array[j];
            ++i;
        }

        while (i < j && array[i] <= povit) ++i;
        if (i < j) {
            array[j] = array[i];
            --j;
        }
    }

    array[i] = povit;
    return i;
}

int EleOfHalfArray(int *array, int length) {
    int low = 0;
    int high = length - 1;
    int povit_index = partition(array, low, high);
    int mid = (low + high) / 2;

    while (mid != povit_index) {
        if (mid > povit_index) {
            low=povit_index+1;
            povit_index = partition(array, low, high);
        } else {
            high=povit_index-1;
            povit_index = partition(array, low, high);
        }
    }

    return array[povit_index];
}


int NumberMoreThanHalfArrayLength(int *array, int length) {
    int num = array[0];
    int count = 1;

    for (int i = 1; i < length; ++i) {
        if (count == 0) {
            num = array[i];
            count = 1;
            continue;
        }

        if (array[i] == num) count++;
        else count--;
    }

    return num;
}


int main(int argc, char **argv) {
    int array[9] = {1, 1, 2, 2, 2, 2, 2, 1, 3};
    cout << EleOfHalfArray(array, 9) << endl;
    cout << NumberMoreThanHalfArrayLength(array, 9) << endl;

    return 0;
}