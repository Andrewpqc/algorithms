#include <iostream>

using namespace std;

/*arr从小到大排序，返回值为-1表示arr中不存在targt
 * 返回值为自然数，则为target在arr中的索引*/
int binary_search(int *arr, int length, int target) {
    int low = 0;
    int high = length - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (target > arr[mid]) low = mid + 1;
        else if (target < arr[mid]) high = mid - 1;
        else return mid;
    }
    return -1;
}


int main(int argc, char **argv) {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << binary_search(array, 10, 12) << endl;
    cout << binary_search(array, 10, 1) << endl;
    return 0;
}