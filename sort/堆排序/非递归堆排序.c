#include <stdio.h>
#include <stdlib.h>

void swap(int *left, int *right)
{
    int tmp = *left;
    *left = *right;
    *right = tmp;
}
//非递归调整堆
void heapify(int *arr, int i, int end)
{
    int key = arr[i];
    int p = i;              
    int left = 2 * p + 1;
    /* 越界就是没孩子 */    /* 只要能进循环，一定有左孩子 */
    while( left < end )
    {
        /* 有右孩子的情况下，大于等于左右孩子不用换 */
        if( (key >= arr[left]) && (left+1 <= end && key >= arr[left+1]))
        {
            break;
        }else if( key >= arr[left] && left + 1 > end) /* 没有右孩子，只有左孩子，且大于等于左孩子不用换*/
        {
            break;
        }else if(left + 1 <= end && arr[left+1] >= arr[left] && key < arr[left+1]) /* 与右孩子换。要保证有右孩子，且右孩子大于等于左孩子，父亲小于右孩子 */
        {
            swap(arr+p, arr+left+1);
            p = left + 1;         //父亲与谁换，就到谁的位置了
             left = 2 * p + 1;      //父亲新的左孩子的位置
        }else if(left + 1 <= end && arr[left] > arr[left + 1] && key < arr[left])/* 与左孩子换。有右孩子的情况下，右孩子小于左孩子，父亲小于左孩子 */
        {
            swap(arr + p, arr + left);
            p = left;
            left = 2 * p + 1;
        }else if(left + 1 > end && arr[left] > key) /* 与左孩子换。没右孩子的情况下，只需父亲小于左孩子 */
        {
            swap(arr + p, arr + left);
            p = left;
            left = 2 * p + 1;
        }
    }    
}


void heap_sort(int * a,int size){
    for(int i=size/2-1;i>=0;i--){
        heapify(a,i,size);
    }
    
    for (int i=size-1; i>0; i--){
		// Move current root to end
		int j=a[i];
        a[i]=a[0];
        a[0]=j;
		// call max heapify on the reduced heap
		heapify(a, 0,i);
	}
}

int main (void){
    int a[5]={1,5,6,2,9};
    heap_sort(a,5);
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }
    return 0;
}