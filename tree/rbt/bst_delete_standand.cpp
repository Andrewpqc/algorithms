/**
 * 下面的是一个标准的二叉树删除函数，没有考虑平衡性
 **/ 
bool RBTree::rbt_delete(int k){
    rbt_node_ptr node = rbt_search(k);
    if(!node){
        cout << "don't have " << k << endl;
        return false;
    }
    bool origin_color=node->color;
    rbt_node_ptr  need_fix_node=NULL;
    //需要删除的节点的两个孩子节点都为空
    if(node->left==NULL&&node->right==NULL){
        if(node->parent==NULL){//删除的是根节点
            delete node;
            this->root=NULL;
        }else{//删除的不为根节点
            if(node==node->parent->left)
                node->parent->left=NULL;
            else
                node->parent->right=NULL;
            delete node;
        }
    }
    //左孩子为空，右孩子不为空
    else if(node->left==NULL&&node->right!=NULL){
        if(node->parent==NULL){//删除的是根节点
            this->root=node->right;
            node->right->parent=NULL;
            delete node;
        }else{//删除的不为根节点
            if(node==node->parent->left)
                node->parent->left=node->right;
            else
                node->parent->right=node->right;
            node->right->parent=node->parent;
            delete node;
        }
    }
    //左孩子不为空，右孩子为空
    else if(node->right==NULL&&node->left!=NULL){
        if(node->parent==NULL){//删除的节点为根节点
            this->root=node->left;
            node->left->parent=NULL;
            delete node;
        }else{//删除的节点不为根节点
            if(node==node->parent->left)
                node->parent->left=node->left;
            else
                node->parent->right=node->left;
            node->left->parent=node->parent;
            delete node;
        }

    }
    //左右孩子均不为空
    else{
        rbt_node_ptr succ_node=rbt_successor(node);
        if (succ_node == node->right){ //后继节点就是node的右孩子
            node->left->parent = succ_node;
            succ_node->left = node->left;
            //删除节点为根节点
            if(node->parent==NULL){
                root=succ_node;
                succ_node->parent=NULL;
            }
            //删除节点不为根节点
            else{
                if(node->parent->left==node)
                    node->parent->left=succ_node;
                else
                    node->parent->right=succ_node;
                succ_node->parent=node->parent;
            }
            delete node;
        }
        else
        { //后继节点不为node的右孩子
            //先用succ_node的右孩子代替succ_node位置,再用原来succ_node代替node的位置
            if (succ_node->parent->left = succ_node->right)
                succ_node->right->parent = succ_node->parent;
            node->left->parent = succ_node;
            succ_node->left = node->left;
            succ_node->right = node->right;
            node->right->parent=succ_node;
            //删除节点为根节点
            if(node->parent==NULL){
                root=succ_node;
                succ_node->parent=NULL;
            }
            //删除节点不为根节点
            else{
                if (node->parent->left == node) 
                    node->parent->left = succ_node;
                else
                    node->parent->right = succ_node;
                succ_node->parent = node->parent;     
            }
            delete node;
            return true;
        }
    }
    return true;
}