/**
 * 红黑树实现
 **/
#include <iostream>
using namespace std;

typedef struct rbt_node{
    int key;
    bool color; //true为红，false为黑
    struct rbt_node *left;
    struct rbt_node *right;
    struct rbt_node *parent;
} rbt_node, *rbt_node_ptr;

rbt_node_ptr parentof(rbt_node_ptr  node){
    if(!node)
        return node;
    return node->parent;    
}

void set_color_to_red(rbt_node_ptr node){
    if(node)
        node->color=true;
}

void set_color_to_black(rbt_node_ptr node){
    if(node)
        node->color=false;
}

bool is_red(rbt_node_ptr node){
    return node->color==true;
}

bool is_black(rbt_node_ptr node){
    return node->color==false;
}

void preorder(rbt_node_ptr root){
    if (root){
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(rbt_node_ptr root){
    if(root){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

void postorder(rbt_node_ptr root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}

//搜索 递归
rbt_node_ptr rbt_search_recursive(rbt_node_ptr root,int k){
    if(!root||root->key==k)
        return root;
    if(k<root->key)
        return rbt_search_recursive(root->left,k);
    else if(k>root->key)
        return rbt_search_recursive(root->right,k);
}

//搜索 迭代
rbt_node_ptr rbt_search_itersive(rbt_node_ptr root,int k){
    while(root && root->key!=k){
        if(k<root->key)
            root=root->left;
        else
            root=root->right;
    }
    return root;
}

//最大值
rbt_node_ptr rbt_minimum(rbt_node_ptr root){
    if(!root)
        return root;
    while(root->left)
         root=root->left;
    return root;
}

//最小值
rbt_node_ptr rbt_maximum(rbt_node_ptr root){
    if(!root)
        return root;
    while(root->right)
        root=root->right;
    return root;
}

//node节点的后继节点
rbt_node_ptr rbt_succressor(rbt_node_ptr root,rbt_node_ptr node){
    if(node->right)//node的右孩子不为空
        return rbt_minimum(node->right);
    else{
        rbt_node_ptr temp=node->parent;
        while(temp&&node!=temp->left){
            temp=temp->parent;
            node=node->parent;
        }
        return temp;
    }
}

//node节点的前驱节点
rbt_node_ptr rbt_predecessor(rbt_node_ptr root,rbt_node_ptr node){
    if(node->left)
        return rbt_maximum(node->left);
    else{
        rbt_node_ptr temp=node->parent;
        while(temp&&node!=temp->right){
            temp=temp->parent;
            node=node->parent;
        }
        return temp;
    }
}

//左旋
static rbt_node_ptr rbt_LL_right_rotate(rbt_node_ptr &root, rbt_node_ptr node){
    rbt_node_ptr temp = node->left; //获取node的左节点

    //将temp的右子树挂到node的左支上，注意处理父子节点
    if (temp->right != NULL){
        node->left = temp->right;
        temp->right->parent = node;
    }

    //处理temp的父指针的指向
    temp->parent = node->parent;

    //如果node的父节点为空，直接将temp挂到root上
    if (node->parent == NULL)
        root = temp;
    else{
        if (node->parent->left == node) //node原来挂在其父节点的左枝上
            node->parent->left = temp;
        else //node原来挂在其父节点的右支上
            node->parent->right = temp;
    }
    temp->right = node;
    node->parent = temp;
    return temp;
}

//右旋
static rbt_node_ptr rbt_RR_left_rotate(rbt_node_ptr& root, rbt_node_ptr node){
    rbt_node_ptr temp = node->right;
    
    if (temp->left != NULL){
        node->right = temp->left;
        temp->left->parent = node;
    }
        
    temp->parent = node->parent;
    if (node->parent == NULL)
        root = temp;
    else{
        if (node->parent->left == node)
            node->parent->left = temp;
        else
            node->parent->right = temp;
    }
    temp->left = node;
    node->parent = temp;
    return temp;
}

//insert_node插入到树root中后的调整函数
static void rbt_insert_fixup(rbt_node_ptr &root, rbt_node_ptr insert_node){
    rbt_node_ptr parent, gparent;

    //父节点存在，并且父节点为红色
    while ((parent = parentof(insert_node)) && is_red(parent)){                             //insert_node的父节点不空且颜色为红色
        gparent = parentof(parent); //insert_node的祖父节点

        //父节点是祖父节点的左孩子
        if (parent == gparent->left){
            rbt_node_ptr uncle = gparent->right;
            if (uncle && is_red(uncle)){ //叔节点存在，并且颜色为红色 case1
                set_color_to_black(uncle);
                set_color_to_black(parent);
                set_color_to_red(gparent);
                insert_node = gparent;
                continue;
            }
            
            if (parent->right == insert_node){ //uncle节点为黑色，并且当前节点位于其父节点的右支上 case2
                rbt_node_ptr tmp;
                rbt_RR_left_rotate(root, parent);
                parent=tmp;
                tmp=insert_node;
                insert_node=parent;
            }
            
            //uncle节点为黑色，并且当前节点位于其父节点的左支上case3
            set_color_to_black(parent);
            set_color_to_red(gparent);
            rbt_LL_right_rotate(root, gparent);  
        }
        else{//父节点位于祖父节点的右支上
            rbt_node_ptr uncle = gparent->left;
            if (uncle && is_red(uncle)){ //叔节点存在，并且颜色为红色 case1
                set_color_to_black(uncle);
                set_color_to_black(parent);
                set_color_to_red(gparent);
                insert_node = gparent;
                continue;
            }
        
            if (parent->left == insert_node){ //uncle节点为黑色，并且当前节点位于其父节点的右支上 case2
                rbt_node_ptr tmp;
                rbt_LL_right_rotate(root, parent);
                parent=tmp;
                tmp=insert_node;
                insert_node=parent;
            }
            
            //uncle节点为黑色，并且当前节点位于其父节点的左支上case3
            set_color_to_black(parent);
            set_color_to_red(gparent);
            rbt_RR_left_rotate(root, gparent);
        }
    }
    set_color_to_black(root);
}

bool rbt_insert(rbt_node_ptr& root, int k){
    //向红黑树中插入一个节点
    rbt_node_ptr current_node = NULL, insert_node = NULL, temp = NULL;
    
    //根据关键字k来创建新的节点
    insert_node = new rbt_node;
    if (!insert_node){
        cout << "分配内存失败!" << endl;
        return false;
    }
    insert_node->key = k;
    insert_node->color = true; //新插入的节点设置为红色
    insert_node->left = NULL;
    insert_node->right = NULL;
    insert_node->parent = NULL;

    //找insert_node应该被插入到的位置
    current_node = root;//不能直接操作root
    while (current_node != NULL){
        temp = current_node;
        if (k < current_node->key)
            current_node = current_node->left;
        else if (k > current_node->key)
            current_node = current_node->right;
        else{ //插入已经存在的键
            cout << "键已经存在" << endl;
            return false;
        }
    }
    //while循环退出之后，说明找到了k所对应节点要插入的地方，此时current_node为空，
    //temp则指向current_node的父节点,此时k应该插入为temp节点的子节点
    if (temp == NULL){
        //temp仍然为初始化时的NULL,则说明此时树为空树，根本就没有进入上面的while循环
        //将节点的颜色直接设置为黑色，然后该节点就为根节点
        set_color_to_black(insert_node);
        root = insert_node;
        return true;
    }
    else{                      //非空树
        if (k < temp->key) //插入为temp节点的左孩子
            temp->left = insert_node;
        else //插入为temp节点的右孩子
            temp->right = insert_node;
        insert_node->parent = temp;
        //插入的是红色节点，需要插入调整函数来调整红黑树
        rbt_insert_fixup(root, insert_node);
        return true;
    }
}

//delete_node从树root中删除后的调整函数
static void rbt_delete_fixup(rbt_node_ptr &root, rbt_node_ptr delete_node){

}

//删除关键字为k的节点
bool rbt_delete(rbt_node_ptr &root, rbt_node_ptr del_node){
    rbt_node_ptr child,parent;
    bool  color;
    
 

}


int main(void){
    rbt_node_ptr root = NULL;
    int a[7] = {1,2,3,5,6,7,8};
    for (int i = 0; i < 7; i++)
        rbt_insert(root, a[i]);

    // preorder(root);
    inorder(root);
    return 0;
}