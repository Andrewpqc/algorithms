/**
 * 随机的遍历数组,下面这种方法可以用来构建一颗随机的二叉搜索树，避免构造出低效的二叉搜索树
 **/ 
#include <iostream>
#include <cstdlib>  // srand rand
#include <ctime>    // time
using namespace std;

void swap(int &a, int &b)  
{  
	int tmp = a;  
	a = b;  
	b = tmp;  
}

/**
 * 随机遍历数组
 */
void Traverse_Random(int arr[], int n)
{
	srand(time(NULL));
	for(int i=n-1; i>=0; --i)
	{
		int j = rand() % (i+1);
		cout << arr[j] << " ";   // 输出
		swap(arr[j], arr[i]);
	}
}

int main() 
{
	int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	Traverse_Random(arr, 9);
	return 0;
}

