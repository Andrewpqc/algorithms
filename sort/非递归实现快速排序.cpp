#include <stdio.h>
struct node
{
    int min;
    int max;
};
void quickSort(int min, int max, int a[])
{
    int key = a[min];
    int i = min;
    int j = max;
    int temp;
    struct node myStack[100];
    int top = 0;
    myStack[top].min = min;
    myStack[top].max = max;
    while (top > -1)
    {
        //min max 记录当前处理的这个区间的左极限和有极限
        i = min = myStack[top].min;
        j = max = myStack[top].max;
        top--;
        key = a[min];
        while (i < j)
        {
            while ((i < j) && (key <= a[j]))
            {
                j--;
            }
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;
            }
            while ((i < j) && (key >= a[i]))
            {
                i++;
            }
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                j--;
            }
        } //处理一次即将比绑定值小的全部放左边 比绑定值大的放右边
        if (min < i - 1)
        {
            top++;
            myStack[top].min = min;
            myStack[top].max = i - 1;
        }
        if (max > i + 1)
        {
            top++;
            myStack[top].min = i + 1;
            myStack[top].max = max;
        }
    }
}
int main()
{
    int i;
    int a[14] = {20,2,52,23,12,14,16,25,10,2,5,9,7,3};
    for (i = 0; i < 14; i++)
        printf(" %d ", a[i]);
    printf("\n");
    quickSort(0, 13, a);
    for (i = 0; i < 14; i++)
        printf(" %d ", a[i]);
    printf("\n");
    return 0;
}