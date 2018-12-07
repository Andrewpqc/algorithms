#include <iostream>
using namespace std;

int findFirstTargetIndex(int* array,int array_length,int target){
    int low =0;
    int high = array_length-1;

    while (low<= high){
        int mid = (low+high)/2;
        if(array[mid]>target){
            high= mid-1;
        } else if (array[mid]<target){
            low=mid+1;
        }else{

            if((mid>=1 && array[mid-1]!=target) || mid==0) return mid;
            else high=mid-1;

        }
    }
    return -1;
}


int findLastTargetIndex(int* array, int array_length, int target){
    int low =0;
    int high = array_length-1;

    while (low<= high){
        int mid = (low+high)/2;
        if(array[mid]>target){
            high= mid-1;
        } else if (array[mid]<target){
            low=mid+1;
        }else{

            if((mid<array_length-1 && array[mid+1]!=target) || mid==array_length-1) return mid;
            else low=mid+1;

        }
    }

    return -1;
}





int main(int argc, char** argv){
    int array[5]={1,2,2,3,5};
    cout<<findFirstTargetIndex(array,5,2)<<endl;
    cout<<findFirstTargetIndex(array,5,10)<<endl;
    cout<<findFirstTargetIndex(array,5,5)<<endl;
    cout<<findFirstTargetIndex(array,5,1)<<endl;
    cout<<findFirstTargetIndex(array,5,3)<<endl;
    cout<<"-----------------------"<<endl;
    cout<<findLastTargetIndex(array,5,2)<<endl;
    cout<<findLastTargetIndex(array,5,1)<<endl;
    cout<<findLastTargetIndex(array,5,5)<<endl;
    cout<<findLastTargetIndex(array,5,3)<<endl;
    cout<<findLastTargetIndex(array,5,10)<<endl;
    
    
    /*last-first+1*/

    return 0;
}