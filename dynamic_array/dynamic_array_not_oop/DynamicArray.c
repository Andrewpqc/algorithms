/**
 * c语言版的动态数组
 * BUG：一个非常大的问题为什么重新分配内存出问题呢？
 */ 
#include <stdio.h>
#include <stdlib.h>

//初始化时分配的容量
#define INIT_CAPACITY 100
//每次重新分配时增加的容量
#define DELTA_CAPACITY 100

typedef int ElementType;
typedef struct DynamicArray{
     //节点容纳的数据
    ElementType* elems;
    //动态数组当前元素的个数
    int size;
    //当前分配的内存可容纳的元素个数(容量)
    int capacity;
} *DynamicArrayPtr;

//初始化动态数组
void init(DynamicArrayPtr DAP){
    DAP->elems=(ElementType*)malloc(sizeof(ElementType)*INIT_CAPACITY);
    DAP->size=0;
    DAP->capacity=INIT_CAPACITY;
}



/**
 * 功能：打印动态数组
 */ 
void print(DynamicArrayPtr DAP) {
	for (int i = 0; i < DAP->size; i++) {
		printf("%d  ", DAP->elems[i]);
    }
    printf("\n");
}

/**
 * 处理动态数组容量不够用时的情况，一般在向动态数组添加数据时使用
 * ＠para:DA为需要操作的动态数组
 */ 
void dealOverflow(DynamicArrayPtr DAP){
    if (DAP->size >= DAP->capacity) {
        // printf("overflow\n");
        ElementType* newbase = (ElementType*)realloc(DAP->elems, (DELTA_CAPACITY + DAP->size)*sizeof(ElementType));
        if(newbase==NULL){
            printf("重新分配内存失败！");
            return ;
        }
        DAP->elems=newbase;
        // printf(">>>>>>>>>>");
        // print(DAP);
		DAP->capacity += DELTA_CAPACITY;
    }
}



/**
 * 功能：向动态数组尾部添加数据
 * ＠para:DA是所要操作的动态数组
 * ＠para:e是所要添加的数据
*/
void append(DynamicArrayPtr DAP,ElementType e){
    dealOverflow(DAP);
    DAP->elems[DAP->size]=e;
    DAP->size++;
}

/**
 * 功能：向动态数组的任意位置插入数据
 * ＠para:DA是所要操作的动态数组
 * ＠para:pos是所要插入的位置(下标值)
 * ＠para:e是所要添加的数据
 */
void insert(DynamicArrayPtr DAP,int pos,ElementType e){
    //若容量不够则重新分配内存
    dealOverflow(DAP);
    //下标超界的处理
    if(pos>DAP->size||pos<0){
        exit(1);
        return;
    }
    //插入数据
    int i;
    for(i=DAP->size;i>pos;i--){
        DAP->elems[i]=DAP->elems[i-1];
    }
    DAP->elems[i]=e;
    DAP->size++;
}


/**
 * 功能：删除动态数组任意位置的数据
 * ＠para:DA是所要操作的动态数组
 * ＠para:pos是所要删除的数据的下标值
 */
void myremove(DynamicArrayPtr DAP,int pos){
    //下标超界的处理
    if(pos>=DAP->size||pos<0){
        exit(1);
        return;
    }

     //删除数据
     int i;
     for(i=pos;i<DAP->size;i++){
         DAP->elems[i]=DAP->elems[i+1];
     }
     DAP->size--;
}

/**
 * 销毁动态数组
 */ 
void destroy(DynamicArrayPtr DAP){
    free(DAP->elems);
	DAP->size = 0;
	DAP->capacity = 0;
}



/**
 * 功能:对动态数组元素排序
 * ＠para:DA为所操作的动态数组
 * ＠para：rule为排序规则，默认为从小到大排序
 */ 
void sort(DynamicArrayPtr DAP,char rule='<'){
        if(rule=='<'){//从小到大排序
            for(int i=0;i<DAP->size;i++){
                for(int j=i+1;j<DAP->size;j++){
                    if(DAP->elems[i]>DAP->elems[j]){
                        int temp=DAP->elems[i];
                        DAP->elems[i]=DAP->elems[j];
                        DAP->elems[j]=temp;
                    }
                }
            }
        }
        else if(rule=='>'){//从大到小排序
            for(int i=0;i<DAP->size;i++){
                for(int j=i+1;j<DAP->size;j++){
                    if(DAP->elems[i]<DAP->elems[j]){
                        int temp=DAP->elems[i];
                        DAP->elems[i]=DAP->elems[j];
                        DAP->elems[j]=temp;
                    }
                }
            }
        }
        else{//rule参数输入错误
            printf("请输入正确的排序规则('<' or '>')!!!");
            exit(1);
        }
}

/**
 * 功能:将两个动态数组DA1,DA2先合并然后排序,将最终结果
 * 保存在DA1中,销毁DA2，默认从小到大排序
 */
 void mergeAndsort(DynamicArrayPtr DAP1,DynamicArrayPtr DAP2,char rule='<'){
    for(int i=0;i<DAP2->size;i++){
        append(DAP1,DAP2->elems[i]);
    }
    //销毁DA2
    destroy(DAP2);
    //排序
    sort(DAP1,rule);
 }


 /**
  * 功能:对两个已经按照相同规则排好序的动态数组合并并按照指定规则排序排序，
  * 根据原始规则与指定的规则的不同有四种排列组合
  * ＠para:DA１，DA2是两个原始的已有序的动态数组
  * ＠para:DA3是最终生成的结果动态数组
  * ＠para:originrule是原始的已排序的动态数组的排序规则('<' or '>')
  * ＠para:rule是合并后的的动态数组的排序规则('<' or '>')
  */ 
 void mergeAndsort_for_sorted(DynamicArrayPtr DA1,DynamicArrayPtr DA2,DynamicArrayPtr DA3,char originrule,char rule='<'){
     if(originrule=='<'&&rule=='<'){
             int i=0,j=0;
             while(i!=DA1->size&&j!=DA2->size){
                 if(DA1->elems[i]<DA2->elems[j]){
                     append(DA3,DA1->elems[i]);
                     i++;
                 }else if(DA1->elems[i]==DA2->elems[j]) {
                     //防止循环的最后一个相同的时候漏掉一个
                     append(DA3,DA1->elems[i]);
                     i++;
                     append(DA3,DA2->elems[j]);
                     j++;
                 }else{
                     append(DA3,DA2->elems[j]);
                     j++;
                 }
             }
             if(DA1->size==i){
                 while(j<DA2->size){
                    append(DA3,DA2->elems[j]);
                     j++;
                 }
                 }
             else if(DA2->size==j){
                 while(i<DA1->size){
                    append(DA3,DA1->elems[i]);
                     i++;
                 }
                 }
     }
     else if(originrule=='>'&&rule=='>'){
        int i=0,j=0;
        while(i!=DA1->size&&j!=DA2->size){
            if(DA1->elems[i]<DA2->elems[j]){
                append(DA3,DA2->elems[j]);
                j++;
            }else if(DA1->elems[i]==DA2->elems[j]) {
                //防止循环的最后一个相同的时候漏掉一个
                append(DA3,DA1->elems[i]);
                i++;
                append(DA3,DA2->elems[j]);
                j++;
            }else{
                append(DA3,DA1->elems[i]);
                i++;
            }
        }
        if(DA1->size==i){
            while(j<DA2->size){
               append(DA3,DA2->elems[j]);
                j++;
            }
            }
        else if(DA2->size==j){
            while(i<DA1->size){
               append(DA3,DA1->elems[i]);
                i++;
            }
            }
     }
     else if(originrule=='<'&&rule=='>'){
        int i=DA1->size-1,j=DA2->size-1;
        while(i!=-1&&j!=-1){
            if(DA1->elems[i]<DA2->elems[j]){
                append(DA3,DA2->elems[j]);
                j--;
            }else if(DA1->elems[i]==DA2->elems[j]) {
                //防止循环的最后一个相同的时候漏掉一个
                append(DA3,DA1->elems[i]);
                i--;
                append(DA3,DA2->elems[j]);
                j--;
            }else{
                append(DA3,DA1->elems[i]);
                i--;
            }
        }
        if(-1==i){
            while(j!=-1){
               append(DA3,DA2->elems[j]);
                j--;
            }
            }
        else if(-1==j){
            while(i!=-1){
               append(DA3,DA1->elems[i]);
                i--;
            }
            }
     }
     else if(originrule=='>'&&rule=='<'){
        int i=DA1->size-1,j=DA2->size-1;
        while(i!=-1&&j!=-1){
            if(DA1->elems[i]<DA2->elems[j]){
                append(DA3,DA1->elems[i]);
                i--;
            }else if(DA1->elems[i]==DA2->elems[j]) {
                //防止循环的最后一个相同的时候漏掉一个
                append(DA3,DA1->elems[i]);
                i--;
                append(DA3,DA2->elems[j]);
                j--;
            }else{
                append(DA3,DA2->elems[j]);
                j--;
            }
        }
        if(-1==i){
            while(j!=-1){
               append(DA3,DA2->elems[j]);
                j--;
            }
            }
        else if(-1==j){
            while(i!=-1){
               append(DA3,DA1->elems[i]);
                i--;
            }
            }
     }
     else{
         printf("原始规则或指定的规则不正确");
         exit(1);
     }
 }


 int main (void){
     /**
      * 测试成功
      */
     DynamicArrayPtr DA1,DA2,DA3;
     init(DA1);
     init(DA2);
     init(DA3);
     append(DA1,1);
     append(DA1,2);
     append(DA1,3);
     print(DA1);
     sort(DA1,'>');
     print(DA1);
     insert(DA1,0,100);
     insert(DA1,2,111);
     append(DA1,1000);
     print(DA1);
     sort(DA1,'<');
     print(DA1);
     myremove(DA1,0);
     print(DA1);

     sort(DA1,'<');
     append(DA2,99999);
     append(DA2,88899);
     append(DA2,99562);
     print(DA2);
    mergeAndsort(DA1,DA2,'<');
    print(DA1);
    append(DA2,25);
    append(DA2,1256);
    append(DA2,2568);
    append(DA2,3333);
    append(DA2,4444);
    append(DA2,5555);
    append(DA2,6666);
    append(DA2,7777);
    append(DA2,8888);
    append(DA2,9999);
    for(int i=0;i<120;i++){
        append(DA2,i);
    }
    print(DA2);
    sort(DA1,'>');
    sort(DA2,'>');
    // mergeAndsort_for_sorted(DA1,DA2,DA3,'>','<');
    print(DA3);
    
    sort(DA1,'<');
    sort(DA2,'<');
    mergeAndsort_for_sorted(DA1,DA2,DA3,'<','>');
    print(DA3);

    
    return 0;
 }