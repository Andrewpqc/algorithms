#include <iostream>
using namespace std;
typedef struct avl_node{
    int key;
    int height;
    struct avl_node* left;
    struct avl_node* right;
}avl_node,*avl_node_ptr;

int get_height(avl_node_ptr node){
    return ((node==NULL)?0:node->height);
}

int max(int a,int b){
    return ((a<b)?b:a);
}

int get_bf(avl_node_ptr node){
    if (node==NULL)
        return 0;
    return get_height(node->left)-get_height(node->right);
}

avl_node_ptr LL_right_rotate(avl_node_ptr node){
    avl_node_ptr t=node->left;
    node->left=t->right;
    t->right=node;
    node->height=max(get_height(node->left),get_height(node->right))+1;
    t->height=max(get_height(t->left),get_height(t->right))+1;
    return t;
}

avl_node_ptr RR_left_rotate(avl_node_ptr node){
    avl_node_ptr t=node->right;
    node->right=t->left;
    t->left=node;
    node->height=max(get_height(node->left),get_height(node->right))+1;
    t->height=max(get_height(t->left),get_height(t->right))+1;
    return t;
}

avl_node_ptr LR_left_right_rotate(avl_node_ptr node){
    node->left=RR_left_rotate(node->left);
    return LL_right_rotate(node);
}   

avl_node_ptr RL_right_left_rotate(avl_node_ptr node){
    node->right=RR_left_rotate(node->right);
    return LL_right_rotate(node);
}

avl_node_ptr re_balance(avl_node_ptr  node){
    if (node == NULL)
        return node;
    int bf=get_bf(node);
    int bf_r=get_bf(node->right);
    int bf_l=get_bf(node->left);

    if(bf>1 && bf_l>0 )//LL
        return LL_right_rotate(node);
    if(bf>1 && bf_l<0)//LR
        return LR_left_right_rotate(node);
    if(bf<-1 && bf_r>0)//RL
        return RL_right_left_rotate(node);
    if(bf<-1 && bf_r<0)//RR
        return RR_left_rotate(node);
    //返回未失衡的指针
    return node;
}

void inorder(avl_node_ptr node){
    if(node){
        inorder(node->left);
        cout<<node->key<<" ";
        inorder(node->right);
    }
}

void preorder(avl_node_ptr node){
    if(node){
        cout<<node->key<<" ";
        preorder(node->left);
        preorder(node->right);
    }
}

avl_node_ptr avl_insert(avl_node_ptr node,int k){
    if(!node){
        node=new avl_node;
        node->key=k;
        node->height=1;
        node->left=NULL;
        node->right=NULL;
        return node;
    }
    if(k<node->key)
        node->left=avl_insert(node->left,k);
    else if(k>node->key)
        node->right=avl_insert(node->right,k);
    else{
        cout<<"can't insert a key that already esixt!"<<endl;
        return node;
    }
    node->height=max(get_height(node->left),get_height(node->right))+1;
    node=re_balance(node);
    return node;
}


avl_node_ptr  avl_delete(avl_node_ptr node,int k){
    if(!node)
        return node;
    if(k<node->key)
        node->left=avl_delete(node->left,k);
    else if(k>node->key)
        node->right=avl_delete(node->right,k);
    else{
        //找到需要删除的节点
        if(node->left==NULL||node->right==NULL){
            //删除的节点只有一个孩子或者没有孩子
            avl_node_ptr temp=(node->left==NULL)?node->right:node->right;
            if(temp==NULL){
                //没有孩子的情况
                temp=node;
                node=NULL;
            }
            else{
                node=temp;
            }
            delete temp;
        }
        else{
            //删除的节点有两个孩子

            avl_node_ptr temp=node->right;
            while(temp->left!=NULL)//找到node的右子树的最小关键字节点
                temp=temp->left;
            node->key=temp->key;
            node->right=avl_delete(node->right,temp->key);
        }
    }
    
    if(node==NULL)
        return node;
    node->height=max(get_height(node->left),get_height(node->right))+1;
    return re_balance(node);
}
int main (void){
    int a[7]={1,2,3,4,5,6,7};
    avl_node_ptr root=NULL;
    for(int i=0;i<7;i++)
        root=avl_insert(root,a[i]);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    root=avl_delete(root,2);
    inorder(root);
    cout<<endl;
    preorder(root);
    return 0;
}