//Select Sort
#include <iostream>
using namespace std;
int main (void){
    int a[10]={8,1,5,3,4,6,27,5,2,9};
    for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }

    for(int k=0;k<10;k++){
        cout<<a[k]<<" ";
    }
    cout<<endl;
    return 0;
}




