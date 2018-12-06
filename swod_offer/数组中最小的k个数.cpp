#include <iostream>
#include <vector>

using namespace std;

int partition(int *array,int low, int high){
    int i=low;
    int j = high;
    int povit = array[low];

    while (i<j){
        while (i<j && array[j]>=povit) --j;
        if(i<j){
            array[i]=array[j];
            ++i;
        }

        while (i<j && array[i]<=povit) ++i;
        if(i<j){
            array[j]=array[i];
            --j;
        }
    }

    array[i]=povit;
    return i;
}


vector<int> KofMin(int* array, int length, int k){
    int low = 0;
    int high = length-1;
    int base_index = partition(array,low,high);
    while (base_index !=k){
        if(base_index >k){
            high =base_index-1;
            base_index = partition(array,low,high);
        } else{
            low=base_index+1;
            base_index = partition(array, low,high);
        }

    }

    vector<int> result;
    for(int i=0;i<base_index;++i){
        result.push_back(array[i]);
    }

    return result;

}


int main(int argc, char** argv){
    int array[] ={1,2,35,0,-1,56,85};
    vector<int> result = KofMin(array,7,2);
    for(auto i:result){
        cout<<i<<" ";
    }
    return 0;
}