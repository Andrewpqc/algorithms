#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define M 15
#define N (2 * M + 1)
using namespace std;

typedef struct node1{
    float weight;
    int parent, lchild, rchild;
} HTNode;

typedef struct node2{
    char data; //待编码各项的名称(本程序规定只能使用一个字符作为名称)
    float weight;
    char code[N];
} HTCode;

void Init(HTCode hc[], int *n){
    int i;
    printf("请输入要编码各项的总项数n=");
    scanf("%d", &(*n));
    // fflush(stdin);//清空输入缓冲区
    printf("输入%d项待编码数的信息\n", *n);
    for (i = 1; i <= (*n); i++){
        printf("第%d项的名称是:", i);
        getc(stdin);
        scanf("%c", &(hc[i].data));
        // fflush(stdin);
    }
    printf("\n 注意：各项待编码数的权重之和应该为1\n");
    for (i = 1; i <= *n; i++){
        printf("\n 第%d项的权重是:", i);
        scanf("%f", &(hc[i].weight));
    }
}

void Select(HTNode ht[], int k, int *s1, int *s2){
    int i;
    for (i = 1; i <= k; i++){
        //如果两个节点已经合并，那么这两个节点就不参与选择最小值
        //而是由他们的父节点和其他未合并过的原节点参与最小值
        if (ht[i].parent == 0){
            *s1 = i;
            break;
        }
    }

    for (i = 1; i <= k; i++){
        if (ht[i].parent == 0 && ht[i].weight < ht[*s1].weight && fabs(ht[i].weight - ht[*s1].weight) > 1e-6)
            *s1 = i;
    }

    //选出已经通过合并生成的父节点和未参加合并的原节点中概率第二小的字符，并把它赋值给s2,s2>s1
    for (i = 1; i <= k; i++){
        if (ht[i].parent == 0 && i != *s1){
            *s2 = i;
            break;
        }
    }

    for (i = 1; i <= k; i++){
        if (ht[i].parent == 0 && i != *s1 && ht[i].weight < ht[*s2].weight && fabs(ht[i].weight - ht[*s2].weight) > 1e-6)
            *s2 = i;
    }
    printf("\n这是*s1:%d\n", *s1);
    printf("\n这是*s2:%d\n", *s2);
}

void HuffmanCoding(HTNode ht[], HTCode hc[], int n){
    char cd[N];
    int i, m, c, f, s1, s2, start;
    //构造二叉树
    m = 2 * n - 1;

    //构造一个有(2n-1)个字符的数列，对其进行初始化
    for (i = 1; i <= m; i++){
        if (i <= n)
            ht[i].weight = hc[i].weight;
        else
            ht[i].weight = 0.0;
        ht[i].parent = ht[i].lchild = ht[i].rchild = 0;
    }

    for (i = n + 1; i <= m; i++){
        Select(ht, i - 1, &s1, &s2);
        ht[s1].parent = i;
        ht[s2].parent = i;
        ht[i].lchild = s1;
        ht[i].rchild = s2;
        ht[i].weight = ht[s1].weight + ht[s2].weight;
    }

    for (i = 1; i <= m; i++){
        printf("\n第%d个节点的权重是:%f", i, ht[i].weight);
        printf("\n第%d个节点的左子节点是:%d", i, ht[i].lchild);
        printf("\n第%d个节点的右子节点是:%d", i, ht[i].rchild);
        printf("\n第%d个节点的父节点是:%d", i, ht[i].parent);
    }
}

int main(void){
    int i, m, n, w[N + 1];
    float l;
    HTNode ht[M + 1];
    HTCode hc[N + 1];
    Init(hc, &n);

    HuffmanCoding(ht, hc, n);
    //输出编码结果
    for (i = 1; i <= n; i++){
        printf("\n %c的编码结果是:%s", hc[i].data, hc[i].code);
        //计算平均码长
        l = 0;
        for (i = 1; i <= n; i++){
            l += strlen(hc[i].code) * hc[i].weight;
        }
        printf("\n哈弗曼编码的平均码长是:%f\n", l);
    }
    return 0;
}