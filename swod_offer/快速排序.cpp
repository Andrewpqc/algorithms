#include <iostream>

using namespace std;

int partition(int *arr, int low, int high) {
    int i = low;
    int j = high;
    int povit = arr[low];/*基点*/
    while (i < j) {
        /*从右向左找到大于基点的节点*/
        while (i < j && arr[j] >= povit) --j;

        /*将找到的这个节点填到arr[low]的坑中*/
        if (i < j) {
            arr[i] = arr[j];
            ++i;
        }

        /*从左向右找到一个大于基点的节点*/
        while (i < j && arr[i] <= povit) ++i;
        if (i < j) {
            /*将该节点填入上面j离开所留下的坑*/
            arr[j] = arr[i];
            --j;
        }
    }

    /*将基点填到最后一个坑中，并返回基点的新位置的索引*/
    arr[i] = povit;
    return i;
}

void quick_sort(int *arr, int low, int high) {
    if (low <= high) {
        int povit = partition(arr, low, high);
        quick_sort(arr, low, povit - 1);
        quick_sort(arr, povit + 1, high);
    }
}


int main(int argc, char **argv) {
    int array[10] = {1, 2, 30, 8, 1, 6, 8, 3, 12};
    quick_sort(array, 0, 9);
    for (int i = 0; i < 10; ++i) {
        cout << array[i] << " ";
    }

    return 0;
}