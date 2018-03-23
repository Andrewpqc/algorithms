/**
 * 好难啊，删除把我删昏头了
 **/ 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#define HEIGHT(n) (((n) == NULL) ? 0 : (n)->h)
#define MAX(a, b) ((a) < (b) ? (b) : (a))
using namespace std;

typedef struct avl_node{
    int key;
    int h;
    struct avl_node *right;
    struct avl_node *left;
} node, *avl_node_ptr;
//root为最小不平衡二叉树的根节点，插入的节点插在root的左孩子的左子树上
//需要将root的左孩子作为新的根节点,右旋
static avl_node_ptr LL_right_rotate(avl_node_ptr root){
    avl_node_ptr new_root = root->left;
    root->left = new_root->right;Seen this question in a real interview be
    new_root->right = root;
    new_root->h = MAX(HEIGHT(new_root->left), HEIGHT(new_root->right)) + 1;
    root->h = MAX(HEIGHT(root->left), HEIGHT(root->right)) + 1;
    return new_root;
}

//插入的节点位于root的右孩子的右子树上，root的右孩子作为新的根节点，左旋
static avl_node_ptr RR_left_rotate(avl_node_ptr root){
    avl_node_ptr new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;
    new_root->h = MAX(HEIGHT(new_root->left), HEIGHT(new_root->right)) + 1;
    root->h = MAX(HEIGHT(root->left), HEIGHT(root->right)) + 1;
    return new_root;
}

//新插入的节点位于root的左孩子rootl的右子树上，
//那么首先需要先对以rootl为根节点的子树进行左旋(RR_left_rotate)
//然后对以root为根节点的子树进行右旋(LL_right_rotate)
static avl_node_ptr LR_left_right_rotate(avl_node_ptr root){
    root->left = RR_left_rotate(root->left);
    return LL_right_rotate(root);
}

//同上
static avl_node_ptr RL_right_left_rotate(avl_node_ptr root){
    root->right = LL_right_rotate(root->right);
    return RR_left_rotate(root);
}

avl_node_ptr avl_insert(avl_node_ptr root, int k){
    if (root == NULL){
        root = (avl_node_ptr)malloc(sizeof(struct avl_node));
        root->h = 1;
        root->key = k;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (k < root->key){
        root->left = avl_insert(root->left, k);
        if ((HEIGHT(root->left) - HEIGHT(root->right)) >= 2){
            if (k < root->left->key)
                root = LL_right_rotate(root);
            else
                root = LR_left_right_rotate(root);
        }
    }
    else if (k > root->key){
        root->right = avl_insert(root->right, k);
        if (abs(HEIGHT(root->right) - HEIGHT(root->left)) >= 2){
            if (k > root->right->key)
                root = RR_left_rotate(root);
            else
                root = RL_right_left_rotate(root);
        }
    }
    else{
        printf("插入失败，关键字不能相同!,已跳过 %d\n", k);
    }
    root->h = MAX(HEIGHT(root->left), HEIGHT(root->right)) + 1;
    return root;
}

//在平衡二叉树中删除关键字为k的节点
avl_node_ptr avl_delete(avl_node_ptr root, int k){
    if (root == NULL){ //如果为空直接返回空
        return root;
    }
    if (k < root->key){
        //此时说明需要删除的节点位于左支上，递归删除
        root->left = avl_delete(root->left, k);
        //左支上删除完成后，有可能对某一个节点的有子树高度比左支高度大2
        if (HEIGHT(root->right) - HEIGHT(root->left) >= 2){
            if (HEIGHT(root->right->right) > HEIGHT(root->right->left)){
                //此时说明root的右孩子的右子树上的节点导致失衡
                root = RR_left_rotate(root);
            }
            else{
                root = RL_right_left_rotate(root);
            }
        }
    }
    else if (k > root->key){
        root->right = avl_delete(root->right, k);
        if (HEIGHT(root->left) - HEIGHT(root->right) >= 2){
            if (HEIGHT(root->left->right) > HEIGHT(root->left->left)){
                root = LR_left_right_rotate(root);
            }
            else{
                root = LL_right_rotate(root);
            }
        }
    }
    else{
        //找到需要删除的节点
        if (root->left && root->right){ //两个孩子
            if (HEIGHT(root->right) > HEIGHT(root->left)){
                avl_node_ptr temp = root->right;
                while (temp->left != NULL){
                    temp = temp->left;
                }
                //找到root的右子树的最小值节点temp
                root->key = temp->key;
                root->left = avl_delete(root->left, root->key);
            }
            else{
                avl_node_ptr temp = root->left;
                while (temp->right != NULL){
                    temp = temp->right;
                }
                //找到root的左子树的最大关键字节点temp
                root->key = temp->key;
                root->right = avl_delete(root->right, root->key);
            }
        }
        else{
            //0个或一个孩子
            avl_node_ptr temp = root;
            root = (root->left == NULL ? root->right : root->left);
            free(temp);
        }
        return root;
    }
}

void inorder(avl_node_ptr root){
    if (root){
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main(void)
{
    avl_node_ptr root = NULL;
    int a[5] = {1, 3, 4, 2, 8};
    for (int i = 0; i < 5; i++)
        root = avl_insert(root, a[i]);
    
    inorder(root);
    cout << endl;
    root=avl_delete(root, 3);
    root=avl_delete(root, 4);
    root=avl_delete(root, 1);
    root=avl_delete(root, 2);

    inorder(root);
    return 0;
}