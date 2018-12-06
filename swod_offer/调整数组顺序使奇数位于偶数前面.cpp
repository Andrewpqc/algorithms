#include <vector>
#include <cassert>
#include <list>
#include <iostream>

using namespace std;

/*是否为偶数*/
bool is_even(int a) {
    if (a & 0x1) return false;
    else return true;
}

void reorder_array(vector<int> &array) {
    int low =0;
    int high = array.size()-1;

    /*array为空或者仅有一个元素，直接返回*/
    if(high<=0) return;

    /*保存待移动的偶数值，以及该偶数值在数组的索引*/
    list<int> evens_need_move;
    list<int> index_of_evens;

    /*保存待移动的奇数值，以及该奇数值在数组中的索引*/
    list<int> odds_need_move;
    list<int> index_of_odds;

    while (low <high){

        while ((low<high) && !is_even(array[low])) ++low;

        while ((low <high) && is_even(array[high])) --high;

        if(low <high) {
            /*不实际操作数组，而是保留待移动的数据
             * 以及他们在数组中的索引*/
            evens_need_move.push_back(array[low]);
            index_of_evens.push_back(low);

            odds_need_move.push_back(array[high]);
            index_of_odds.push_back(high);

            ++low;
            --high;
        }
    }

    /*此时low和high一定指向相同的元素*/
    assert(low == high);

    /*此时表明元素为全奇数或全偶数*/
    if(low == 0 || low ==array.size()-1) return;

    //插入奇数
    while (!odds_need_move.empty()){
        int need_be_insert = odds_need_move.front();
        odds_need_move.pop_front();

        int insert_place = index_of_evens.back();
        index_of_evens.pop_back();

        array[insert_place]=array[low-1];
        array[low -1]= need_be_insert;

        --low;
    }


    //插入偶数
    //如果没有偶数需要移动，直接返回
    if(evens_need_move.size()==0) return;
//    for(int i=;)
    while (!evens_need_move.empty()){

        int need_be_insert = evens_need_move.front();
        evens_need_move.pop_front();

        int insert_place = index_of_odds.back();
        index_of_odds.pop_back();

        array[insert_place]=array[high];
        array[high]= need_be_insert;

        ++high;
    }

}


int main(int argc, char** argv){

    vector<int> arr {1,2,3,4,5};
    reorder_array(arr);
    for(auto i:arr){
        cout<<i<<" ";
    }

    cout<<endl;

    vector<int> arr2 {2, 4, 6, 8, 10};
    reorder_array(arr2);
    for(auto i:arr2){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> arr3 {1, 3, 5, 7, 9};
    reorder_array(arr3);
    for(auto i:arr3){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> arr4 {1,1,1,1,1};
    reorder_array(arr4);
    for(auto i:arr4){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> arr5 {2,2,2,2,2};
    reorder_array(arr5);
    for(auto i:arr5){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> arr6 {1,2,5,0,8,3,2,8,6};
    reorder_array(arr6);
    for(auto i:arr6){
        cout<<i<<" ";
    }
    cout<<endl;

}