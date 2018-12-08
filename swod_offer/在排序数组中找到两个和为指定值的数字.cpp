#include <iostream>

using namespace std;


bool FindTwoNumbersWithSumInAnOrderedArray(int* array, int len, int targetSum){
    int low = 0;
    int high = len -1;
    int current_sum=0;
    while (low <high){
        current_sum = array[low]+array[high];

        if(current_sum<targetSum) ++low;
        else if(current_sum> targetSum) --high;
        else {
                cout<< array[low] <<" "<< array[high]<<endl;

//            return true;
        }

    }

    return false;
}



int main(int argc, char** argv){
    int  arr[] ={1,2,3,4,5,6};
    FindTwoNumbersWithSumInAnOrderedArray(arr,6,8);

    return 0;
}