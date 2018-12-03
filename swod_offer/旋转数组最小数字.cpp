#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> &rotateArray) {
        int low = 0;
        int high = (int)rotateArray.size()-1;

        int mid = (low + high) / 2;
        if(rotateArray[mid]>rotateArray[low]) low =mid;

        if(rotateArray[mid])


    }
};