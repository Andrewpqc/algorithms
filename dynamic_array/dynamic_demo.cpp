
#include<iostream>
#include<cstdlib>
#define INIT_SIZE 100
#define INC_SIZE 100
using namespace std;
//顺序表定义
typedef struct {
	int* elems;
	int len;
	int size;
} ArrayList;

//初始化顺序表
void init(ArrayList& list) {
	list.elems = (int *)
		malloc(sizeof(int) 
		* INIT_SIZE);
	list.size = INIT_SIZE;
	list.len = 0;
}

//打印顺序表
void print(ArrayList& list) {
	for (int i = 0; i < list.len; i++) {
		printf("%d\n", list.elems[i]);
	}
}

//销毁顺序表
void destroy(ArrayList& list) {
	free(list.elems);
	list.len = 0;
	list.size = 0;
}

//向顺序表index位置插入元素e
void insert(ArrayList& list, int index, int e) {
	if (list.len >= list.size) {
		list.elems = (int *)realloc(list.elems, 
			sizeof(int) * 
			(INC_SIZE + list.size));
		list.size += INC_SIZE;
	}
	for (int i = list.len - 1; 
		i >= index; i--) {
		list.elems[i + 1] = list.elems[i];
	}
	list.elems[index] = e;
	list.len++;
}

//向顺序表末尾插入元素e
void add(ArrayList& list, int e) {
	insert(list, list.len, e);
}

//删除顺序表index位置的元素
void remove(ArrayList& list, int index) {
	for (int i = index; i <= list.len - 2; i++) {
		list.elems[i] = list.elems[i + 1];
	}
	list.len--;
}

//请自行填充合并函数merge
void merge(ArrayList& list1,ArrayList& list2,ArrayList& list3){
	/**
	*归并排序
	*/
	int minLen=(list1.len>list2.len)?list2.len:list1.len;
	int i=0,j=0;
	while(i<minLen&&j<minLen){
		if(list1.elems[i]<list2.elems[j]){
			add(list3,list1.elems[i]);
			i++;
		}else if(list1.elems[i]==list2.elems[j]) {
			//防止循环的最后一个相同的时候漏掉一个
			add(list3,list1.elems[i]);
			add(list3,list1.elems[i]);
			i++;
			j++;
		}else{
			add(list3,list2.elems[j]);
			j++;
		}
	}
	if(list1.len==minLen){
		while(j<list2.len){
			add(list3,list2.elems[j]);
			j++;
		}
		}
	else if(list2.len==minLen){
		while(i<list1.len){
			add(list3,list1.elems[i]);
			i++;
		}
		}
	}



/*
* 两顺序表分别为1, 3, 7和2, 4, 5，正确实现merge函数后会输出1,2,3,4,5,7
*/
void testBasic() {
	ArrayList list1, list2, list3;
	init(list1);init(list2);init(list3);
	int list1Count,list2Count;
	cout<<"list1中有多少个有序数据：";
	cin>>list1Count;
	for(int i=0;i<list1Count;i++){
		int temp;
		cout<<"第"<<i+1<<"个数：";
		cin>>temp;
		add(list1,temp);
	}
	cout<<"list2中有多少个有序数据：";
	cin>>list2Count;
	for(int i=0;i<list2Count;i++){
		int temp;
		cout<<"第"<<i+1<<"个数：";
		cin>>temp;
		add(list2,temp);
	}
	merge(list1, list2, list3);
	print(list3);
	destroy(list1);destroy(list2);destroy(list3);
}

int main() {
	testBasic();
	return 0;
}