/**
 * 二叉搜索树：
 * 创建二叉搜索树，递归和非递归插入，创建
 * 遍历二叉搜索树　前中后
 * 搜寻二叉搜索树　最大的节点，最小节点，具有指定关键字的节点，前驱，后继
 * 删除指定节点
 **/ 
#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct node{
    int key;//节点数据

    //下面的为二叉搜索树的维护数据
    struct node* parent=NULL;
    struct node* left=NULL;
    struct node* right=NULL;
}BST,*BST_p;

/**
 * 递归构造搜索二叉树
 * root：指向树的根节点的指针
 * k:待插入的key
 * parent:父节点的指针
 **/ 
void bst_insert(BST_p& root,int k,BST_p parent=NULL){
    //如果当前二叉搜索树为空，则当前的待插入的值就为根节点中存放的值
    if(root==NULL){
        root=new BST;
        root->key=k;
        root->lls
        eft=NULL;
        root->right=NULL;
        root->parent=parent;//根节点没有父节点
    }
    else{
        //关键字比root节点中存放的关键字大，那么该节点应该被存放在root节点的右子树
        if(k>root->key){
            bst_insert(root->right,k,root);
        }
        //关键字比root节点中存放的关键字小，那么该节点应该被存放在root节点的左子树
        else{
            bst_insert(root->left,k,root);
        }
    }
}

/**
 * 非递归插入操作
 **/ 
void bst_insert_nonRecur(BST_p& root,int k){
    BST_p pre=NULL;//记录上一个节点
    BST_p t=root;//不能直接使用root操作，这里的root为主函数中的全局root的引用，对他的更改会影响全局的root

    //按照规则找到key应该插入的位置，并用pre记录该位置的上一个节点
    while(t != NULL){
		pre = t;
		if(k < t->key)
			t = t->left;
		else
			t = t->right;
	}

	BST_p node = new BST;
	node->key = k;
	node->left = NULL;
	node->right = NULL;
	node->parent = pre;

    //将node连接到树上
	if(pre == NULL)//若为空树，node即为根节点
		root = node;
	else{//树非空，则判断node应该被连接到pre的左子树还是右子树
		if(k < pre->key)
			pre->left = node;
		else
			pre->right = node;
	}
}

/**
 * 中序遍历二叉搜索树
 **/ 

void inorder_tree_walk(BST_p root){
    if(root!=NULL){
        inorder_tree_walk(root->left);
        cout<<root->key<<" ";
        inorder_tree_walk(root->right);
    }
}

/**
 * 前序遍历二叉树
 **/ 
void preorder_tree_walk(BST_p root){
    if(root!=NULL){
        cout<<root->key<<" ";
        preorder_tree_walk(root->left);
        preorder_tree_walk(root->right);
    }
}

/**
 * 后序遍历二叉树
 **/
void postorder_tree_walk(BST_p root){
    if(root!=NULL){
        postorder_tree_walk(root->left);
        postorder_tree_walk(root->right);
        cout<<root->key<<" ";        
    }
}

/**
 * 找最大值,一直向右找，直到找到最右边的一个节点
 **/ 
BST_p maximum(BST_p& root){
    if(root==NULL){
        cout<<"该树为空，没有最大值"<<endl;
        exit(EXIT_FAILURE);
    }
    else{
        BST_p t=root;//不能用root直接操作
        //找到最右边的那个节点
        while(t->right!=NULL)
            t=t->right;
        return t;
    }         
}

/**
 * 找最小值，一直向左找，直到找到最左边的一个节点
 **/ 
BST_p minimum(BST_p& root){
    if(root==NULL){
        cout<<"该树为空，没有最小值!"<<endl;
        exit(EXIT_SUCCESS);
    }
    else{
        BST_p t=root;//不能用root直接操作
        //找到最左边的那个节点
        while(t->left!=NULL)
            t=t->left;
        return t;
    }
}


/**
 * 查找包含关键字k的节点，并返回指向该节点的指针
 * 这里假设树中的key不重复
 **/ 
BST_p bst_search(BST_p& root,int k){
    if(root==NULL || k==root->key)
        return root;
    else{
        if(k<root->key)
            return bst_search(root->left,k);
        else
            return bst_search(root->right,k);
    }
}

/**
 * 非递归查找
 **/ 

BST_p bst_search_nonRecur(BST_p& root,int k){
    if(root==NULL)//为空时，直接返回NULL
        return root;
    //不为空
    BST_p t=root;
    while(k!=t->key){//依次遍历，直到k与t指向的key相等
        if(k<t->key)//如果k小于当前节点的key，那么就需要到当前节点的左子树中去找
            t=t->left;
        else//如果k大于当前节点的key，那么就需要到当前节点的右子树中去找
            t=t->right;
    }
    return t;
}

/**
 * 前驱(predecessor)与后继(successor)
 * 已知某一个节点a，求该节点a在中序遍历中的后继节点b：
 * 如果该节点a的右孩子不为空，那么其后继b就为a的右子树的的最小值；
 * 如果该节点a的右孩子为空，那么其后继节点就是这么一个节点b:
 * b是a的祖先节点(注意不一定是a的直接祖先)，并且b的左节点也是a的祖先节点
 * 
 * 后继的情况与上述情况相反
 **/ 

/**
 * 找node的后继节点,如果没有后继节点则返回NULL
**/
BST_p successor(BST_p node){
    if(node->right!=NULL)
        return minimum(node->right);
    else{
        BST_p p=node->parent;
        while(p!=NULL&&node!=p->left){
            node=node->parent;
            p=p->parent;
        }
        return p;
    }
}

/**
 * 找前驱，返回指向前驱节点的指针，
 * 如果没有前驱节点则返回NULL
**/
BST_p perdecessor(BST_p node){
    if(node->left!=NULL)
        return maximum(node->left);
    else{
        BST_p p=node->parent;
        while(p!=NULL&&node!=p->right){
            node=node->parent;
            p=p->parent;
        }
        return p;
    }
}

/**
 * 二叉查找树删除指定的节点
 **/ 
void bst_delete(BST_p node){
    //如果需要删除的这个节点的左右子节点均为空，需要做的操作就是
    //先找到该节点的父节点，然后判断该节点是其父节点的左孩子还是右孩子，然后将父节点中指向该节点的指针置空
    //还需要释放该节点占用的内存
    if(node->left==NULL&&node->right==NULL){
        BST_p p=node->parent;
        if(node->key<p->key)//这里说明node节点是其父节点的左节点
            p->left=NULL;//置空左指针
        else
            p->right=NULL;//置空右指针
        //释放node指向的内存块的内存
        delete node;
    }

    //如果需要删除的节点只有一个孩子节点的话，需要进行的操作是：
    //找到该节点(假设为a)的父节点(假设为b)和孩子节点(c)，然后跟据
    //a,b之间的大小关系来判断a是b的左孩子还是右孩子，根据b,c之间的大小关系
    //来判断c是b的左孩子还是右孩子，然后依据三者之间的关系，按照查找二叉树的定义
    //来重新连接c与b,最后要注意释放a所指向的内存块
    else if(node->left==NULL || node->right==NULL){
        BST_p p=node->parent;
        if(node->key>p->key){//node是p的右孩子
            if(node->right==NULL){
                p->right=node->left;
                node->left->parent=p;
            }else{
                p->right=node->right;
                node->right->parent=p;
            }
        }else{
            if(node->right==NULL){
                p->left=node->left;
                node->left->parent=p;
            }else{
                p->left=node->right;
                node->right->parent=p;
            }
        }
        delete node;
    }

    //如果需要删除的节点d有两个孩子a,b的话，需要进行下面的操作：
    //找到节点d的后继节点successor(显然successor肯定在d的右子树上，因为此时d存在右节点)
    //下面要分两种情况讨论了，successor是否为d的右节点。
    //如果successor就为d的右节点：直接将successor替换d，然后将d的左子树连接到successor的左节点上(原本successor的左孩子为空)
    //如果successor不为d的右节点：首先将让successor的右节点替换successor,然后让successor替换d
    //注意上面两种情况都要注意删除d所指向的内存块
    else if(node->left!=NULL&& node->right!=NULL){
        BST_p left=node->left;//左子树的根节点
        BST_p right=node->right;//右子树的根节点
        BST_p parent=node->parent;//父节点
        BST_p successor=minimum(right);//node节点的后继节点,由于存在右子树，所以这里直接使用了求右子树的最小节点的函数
        if(successor->key==right->key){//后继节点就是node的右孩子，这里假设树中不存在key值相同的节点
            //将node的左支连接到后继节点的左孩子上(初始时该节点为空)
            successor->left=left;
            left->parent=successor;
            //将后继节点提升到node的位置
            //这里首先需要判断node是其父节点的左孩子还是右孩子
            if(node->key>parent->key){
                //node是其父节点的右节点
                parent->right=successor;
                successor->parent=parent;
            }else{
                 //node是其父节点的左节点
                parent->left=successor;
                successor->parent=parent;
            }
        }else{
            //后继节点successor不是node的右孩子
            //首先将successor的右节点提升到successor的位置，然后将node的左支连接到
            //successor的左支上(初始为空支)，然后将successor提升到node的位置

            BST_p succ_parent=successor->parent;//后继节点的父节点
            
            //这里后继节点一定位于其父节点的左支，所以直接将后继节点的右节点连接到
            //后继节点的父节点的左支上
            succ_parent->left=successor->right;
            successor->right->parent=succ_parent;

            //将node的左子树连接到后继节点的左支上(该支初始时为空)
            successor->left=left;
            left->parent=successor;

            //将successor提升到node的位置，同样的需要判断node位于其父结点的左还是右
            if(node->key>parent->key){
                //node是其父节点的右节点
                parent->right=successor;
                successor->parent=parent;
            }else{
                 //node是其父节点的左节点
                parent->left=successor;
                successor->parent=parent;
            }
        }
        delete node;
    }

}

int main (void){
    //指向根节点的指针
    BST_p root=NULL;
    
    int a[5]={1,5,3,4,8};
    for(int i=0;i<5;i++){
        // bst_insert(root,a[i]);
        bst_insert_nonRecur(root,a[i]);
    }
    cout<<"中序遍历："<<endl;
    inorder_tree_walk(root);
    cout<<endl;
    cout<<"前序遍历："<<endl;
    preorder_tree_walk(root);
    cout<<endl;
    cout<<"后序遍历："<<endl;
    postorder_tree_walk(root);
    cout<<endl;

    cout<<"最小值："<<endl;
    cout<<minimum(root)->key<<endl;
    cout<<"最大值："<<endl;
    cout<<maximum(root)->key<<endl;


    // BST_p p=bst_search(root,5);
    // BST_p p=bst_search_nonRecur(root,5);
    // p->key=100;
    // cout<<"中序遍历："<<endl;
    // inorder_tree_walk(root);
    // cout<<endl;
    //找4的后继
    BST_p p2=bst_search_nonRecur(root,8);
    BST_p su=successor(p2);
    BST_p pre=perdecessor(p2);
    // cout<<"8的后继是："<<su->key<<endl;
    cout<<(su==NULL)<<endl;
    cout<<"8的前驱是："<<pre->key<<endl;
    cout<<"中序遍历："<<endl;
    inorder_tree_walk(root);
    cout<<endl;

    bst_delete(pre);
    bst_delete(p2);
    inorder_tree_walk(root);

    return 0;
}