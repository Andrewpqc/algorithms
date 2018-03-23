#include <stdio.h>
#include <stdlib.h>
int m[7][7]={0};
int s[7][7]={0};
void Print_Optimal_Parens(int s[][7],int i,int j)  //构造最优解
{
   if ( i ==j)
   {
       printf("A%d",i);
   }
   else
   {
       printf("(");
       Print_Optimal_Parens(s,i,s[i][j]);
       Print_Optimal_Parens(s,s[i][j]+1,j);
       printf(")");
   }
}
void Matrix_Chain_Order(int p[],int n)
{
   int i,j,L,k,q;
   for (i=1;i<=n;i++)      //先对单个矩阵的链，求解，即所有m[i][i] =0;
   {
     m[i][i]=0;          
   }
   for(L=2;L<=n;L++)     //从两个矩阵链开始，逐次增加矩阵链的长度
       for(i=1;i<=n-L+1;i++)  //在给定p[]中的矩阵链中，对所有种长度为L的情况计算
       {
           j = i+L-1;
           m[i][j] = -1;
           for(k=i;k<=j-1;k++)   //遍历所有可能的划分点k，计算出最优的划分方案，
           {
             q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
             if ( q < m[i][j] || m[i][j] == -1)  
             {
                m[i][j] = q;     //最优的代价q保存在m[i][j]中
                s[i][j] = k;     //最优的划分位置k保存在s[i][j]中
             }
           }
       }

}
int main()
{
    int p[]={30,35,15,5,10,20,25};    //矩阵的输入
    int length = sizeof(p)/sizeof(p[0])-1;   //矩阵长度
    int i,j;
    Matrix_Chain_Order(p,length);

    for(i =1;i<=6;i++)
    {
        for (j=1;j<=6;j++)
        {
            printf("%8d",m[i][j]);
        }
        printf("\n");
    }

    Print_Optimal_Parens(s,1,6);
    printf("\n");
    return 0;
}