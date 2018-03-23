#include <iostream>
#include <queue>
#include <stack>
using namespace std;
typedef struct rbt_node{
    int key;
    bool color; //true is red,false is black
    struct rbt_node *left;
    struct rbt_node *right;
    struct rbt_node *parent;
    rbt_node(int k) : key(k), color(true), parent(NULL), left(NULL), right(NULL) {}
} rbt_node, *rbt_node_ptr;

class RBTree{
  private:
    rbt_node_ptr root;

  protected:
    void LL_right_rotate(rbt_node_ptr node);
    void RR_left_rotate(rbt_node_ptr node);
    void rbt_insert_fixup(rbt_node_ptr node);
    void rbt_delete_fixup(rbt_node_ptr child,rbt_node_ptr parent);
    void rbt_destory(rbt_node_ptr node);

  public:
    RBTree();
    ~RBTree();
    rbt_node_ptr rbt_maximum();
    rbt_node_ptr rbt_minimum();
    rbt_node_ptr rbt_successor(rbt_node_ptr node);
    rbt_node_ptr rbt_predecessor(rbt_node_ptr node);
    rbt_node_ptr rbt_search(int k);
    bool rbt_delete(int k);
    bool rbt_insert(int k);
    void preorder_tree_walk();
    void inorder_tree_walk();
    void postorder_tree_walk();
    void levelorder_tree_walk();
};

void RBTree::rbt_destory(rbt_node_ptr node){
    if (node){
        rbt_destory(node->left);
        rbt_destory(node->right);
        cout << "destory " << node->key << endl;
        delete node;
    }
}

RBTree::RBTree(){
    this->root = NULL;
}

RBTree::~RBTree(){
    this->rbt_destory(this->root);
}

rbt_node_ptr RBTree::rbt_maximum(){
    if (!this->root)
        return this->root;
    rbt_node_ptr temp = this->root;
    while (temp->right != NULL)
        temp = temp->right;
    return temp;
}

rbt_node_ptr RBTree::rbt_minimum(){
    if (!this->root)
        return this->root;
    rbt_node_ptr temp = this->root;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

rbt_node_ptr RBTree::rbt_successor(rbt_node_ptr node){
    if (!node)
        return NULL;
    if (node->right){
        rbt_node_ptr temp = node->right;
        while (temp->left != NULL)
            temp = temp->left;
        return temp;
    }
    else{
        rbt_node_ptr temp = node->parent;
        while (temp && temp->left != node){
            temp = temp->parent;
            node = node->parent;
        }
        return temp;
    }
}

rbt_node_ptr RBTree::rbt_predecessor(rbt_node_ptr node){
    if (!node)
        return node;
    if (node->left){
        rbt_node_ptr temp = node->left;
        while (temp->right != NULL)
            temp = temp->right;
        return temp;
    }
    else{
        rbt_node_ptr temp = node->parent;
        while (temp && temp->right != node){
            temp = temp->parent;
            node = node->parent;
        }
        return temp;
    }
}

rbt_node_ptr RBTree::rbt_search(int k){
    rbt_node_ptr node = this->root;
    while (node && node->key != k){
        if (k < node->key)
            node = node->left;
        else if (k > node->key)
            node = node->right;
    }
    return node;
}

void RBTree::preorder_tree_walk(){
    stack<rbt_node_ptr> s;
    rbt_node_ptr p = this->root;
    while (p != NULL || !s.empty()){
        while (p != NULL){
            cout << p->key << " ";
            s.push(p);
            p = p->left;
        }
        if (!s.empty()){
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

void RBTree::inorder_tree_walk(){
    stack<rbt_node_ptr> s;
    rbt_node_ptr p = root;
    while (p != NULL || !s.empty()){
        while (p != NULL){
            s.push(p);
            p = p->left;
        }
        if (!s.empty()){
            p = s.top();
            cout << p->key << " ";
            s.pop();
            p = p->right;
        }
    }
}

void RBTree::postorder_tree_walk(){
    ;
}

void RBTree::levelorder_tree_walk(){
    int parentSize = 1, childSize = 0;
    rbt_node_ptr temp;
    queue<rbt_node_ptr> q;
    q.push(this->root);
    do{
        temp = q.front();
        cout << temp->key << "  ";
        q.pop();

        if (temp->left != NULL){
            q.push(temp->left);
            childSize++;
        }
        if (temp->right != NULL){
            q.push(temp->right);
            childSize++;
        }
        parentSize--;
        if (parentSize == 0){
            parentSize = childSize;
            childSize = 0;
            cout << endl;
        }
    } while (!q.empty());
}

void RBTree::LL_right_rotate(rbt_node_ptr node){
    rbt_node_ptr temp = node->left;
    if (node->left = temp->right)
        temp->right->parent = node;
    temp->parent = node->parent;
    if (!node->parent){
        //这里需要做什么吗？想想为什么?
        this->root = temp;
    }
    else{
        if (node == node->parent->left)
            node->parent->left = temp;
        else
            node->parent->right = temp;
    }
    temp->right = node;
    node->parent = temp;
}

void RBTree::RR_left_rotate(rbt_node_ptr node){
    rbt_node_ptr temp = node->right;
    if (node->right = temp->left)
        temp->left->parent = node;
    temp->parent = node->parent;
    if (!node->parent){
        //这里需要做什么吗？想想为什么?
        this->root = temp;
    }
    else{
        if (node == node->parent->left)
            node->parent->left = temp;
        else
            node->parent->right = temp;
    }
    temp->left = node;
    node->parent = temp;
}


/**
 * 注释中的父节点，叔叔节点，祖父节点都是以被插入节点为参照物来讲的
 **/
void RBTree::rbt_insert_fixup(rbt_node_ptr node){
    rbt_node_ptr parent, grandpa, uncle, temp;
    //node的父节点不存在，说明当前插入的节点为根节点，根节点直接涂黑即可，不需要调整，
    //在插入的主函数中即可处理，不需要调用本修正函数

    //node的父节点存在，但是颜色为黑色，此时没有违背任何红黑树的规则，不需要处理

    //父节点存在，并且父节点的颜色为红色
    while ((parent = node->parent) != NULL && parent->color == true){
        grandpa = parent->parent; //祖父节点一定存在,并且一定为黑色
        //下面分两种大情况讨论:1.父节点为祖父节点的左孩子，2.父节点为祖父节点的右孩子
        if (parent == grandpa->left)
        {
            uncle = grandpa->right;
            /**
             * 场景:父节点为红色，叔叔节点为红色,
             * 调整:将父亲节点和叔叔节点都涂成黑色，
             *     然后将爷爷节点涂成红色，并且让爷爷节点充当新的被插入节点，
             *     然后进入下一轮循环
             **/
            if (uncle && uncle->color == true){
                parent->color = false;
                uncle->color = false;
                grandpa->color = true;
                //这里将祖父节点涂为了红色，有可能祖父节点的父亲也为红色，这种情况就又冲突了
                //这时可以将祖父节点当做新的插入的节点，进入下一轮循环即可
                node = grandpa;
                continue;
            }

            /**
             * 场景二:父节点为红色，叔叔节点为黑色，当前节点(也就是node)是其父节点的左孩子
             * 处理:将父节点颜色设置为黑色，祖父节点的颜色设置为红色，然后以祖父节点为支点
             * (也就是将祖父节点指针作为参数传入LL_right_rotate)右旋
             **/
            if (node == parent->right){
                rbt_node_ptr temp;
                this->RR_left_rotate(parent);
                temp = node;
                node = parent;
                parent = temp;
            }

            parent->color = false;
            grandpa->color = true;
            this->LL_right_rotate(grandpa);
        }
        else{
            uncle = grandpa->left;
            if (uncle && uncle->color == true){
                parent->color = false;
                uncle->color = false;
                grandpa->color = true;
                //这里将祖父节点涂为了红色，有可能祖父节点的父亲也为红色，这种情况就又冲突了
                //这时可以将祖父节点当做新的插入的节点，进入下一轮循环即可
                node = grandpa;
                continue;
            }

            /**
             * 场景二:父节点为红色，叔叔节点为黑色，当前节点(也就是node)是其父节点的左孩子
             * 处理:将父节点颜色设置为黑色，祖父节点的颜色设置为红色，然后以祖父节点为支点
             * (也就是将祖父节点指针作为参数传入LL_right_rotate)右旋
             **/
            if (node == parent->left){
                rbt_node_ptr temp;
                this->LL_right_rotate(parent);
                temp = node;
                node = parent;
                parent = temp;
            }

            parent->color = false;
            grandpa->color = true;
            this->RR_left_rotate(grandpa);
        }
    }
    root->color = false;
}

bool RBTree::rbt_insert(int k){
    rbt_node_ptr node = new rbt_node(k);
    if (node == NULL){
        cout << "分配内存失败!" << endl;
        return false;
    }

    rbt_node_ptr temp = NULL, current_node = NULL;
    current_node = this->root;
    while (current_node != NULL){
        temp = current_node;
        if (k < current_node->key)
            current_node = current_node->left;
        else if (k > current_node->key)
            current_node = current_node->right;
        else{
            cout << k << " 已经存在!" << endl;
            return false;
        }
    }
    if (!temp){
        //直接涂黑，放到根节点
        node->color = false;
        this->root = node;
    }
    else{
        if (k < temp->key){
            temp->left = node;
            node->parent = temp;
        }
        else{
            temp->right = node;
            node->parent = temp;
        }
        this->rbt_insert_fixup(node);
    }
    return true;
}

void RBTree::rbt_delete_fixup(rbt_node_ptr node,rbt_node_ptr parent){
    rbt_node_ptr other;
    while ((!node || node->color==false) && node != root)
    {
        if (parent->left == node)
        {
            other = parent->right;
            if (other->color==true)
            {
                // Case 1: x的兄弟w是红色的  
                other->color=false;
                parent->color=true;
                RR_left_rotate(parent);
                other = parent->right;
            }
            if ((!other->left || other->left->color==false) &&(!other->right || other->right->color==false))
            {
                // Case 2: x的兄弟w是黑色，且w的俩个孩子也都是黑色的  
                other->color=true;
                node = parent;
                parent = node->parent;
            }
            else
            {
                if (!other->right || other->right->color==false)
                {
                    // Case 3: x的兄弟w是黑色的，并且w的左孩子是红色，右孩子为黑色。  
                    other->left->color=false;
                    other->color=true;
                    LL_right_rotate(other);
                    other = parent->right;
                }
                // Case 4: x的兄弟w是黑色的；并且w的右孩子是红色的，左孩子任意颜色。
                other->color=parent->color;
                parent->color=false;
                other->right->color=false;
                RR_left_rotate(parent);
                node = root;
                break;
            }
        }
        else
        {
            other = parent->left;
            if (other->color==true)
            {
                // Case 1: x的兄弟w是红色的  
                other->color=false;
                parent->color=true;
                LL_right_rotate(parent);
                other = parent->left;
            }
            if ((!other->left || other->left->color==false) &&
                (!other->right || other->right->color==false))
            {
                // Case 2: x的兄弟w是黑色，且w的俩个孩子也都是黑色的  
                other->color=true;
                node = parent;
                parent = node->parent;
            }
            else
            {
                if (!other->left || other->left->color==false)
                {
                    // Case 3: x的兄弟w是黑色的，并且w的左孩子是红色，右孩子为黑色。  
                    other->right->color=false;
                    other->color=true;
                    RR_left_rotate(other);
                    other = parent->left;
                }
                // Case 4: x的兄弟w是黑色的；并且w的右孩子是红色的，左孩子任意颜色。
                other->color=parent->color;
                parent->color=false;
                other->left->color=false;
                LL_right_rotate(parent);
                node = root;
                break;
            }
        }
    }
    if (node)
        node->color=false;
}

bool RBTree::rbt_delete(int k){
    rbt_node_ptr node = rbt_search(k);
    if(!node){
        cout << "don't have " << k << endl;
        return false;
    }

    bool origin_color=node->color;
    rbt_node_ptr child,parent=node->parent;
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
        child=node->right;
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
        child=node->left;
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
        origin_color=succ_node->color;
        child=succ_node->right;
        parent=succ_node->parent;
        if (succ_node == node->right){ //后继节点就是node的右孩子
            node->left->parent = succ_node;
            succ_node->left = node->left;
            succ_node->color=node->color;
            //删除节点为根节点
            if(node->parent==NULL){
                root=succ_node;
                root->color=false;
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
                root->color=false;
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
        }
    }

    if(origin_color==false){
        rbt_delete_fixup(child,parent);
    }
    return true;
}

int main(void){
    RBTree t1;
    t1.rbt_insert(1);
    t1.rbt_insert(2);
    t1.rbt_insert(3);
    t1.rbt_insert(4);
    t1.rbt_insert(5);
    t1.rbt_insert(100);
    t1.rbt_insert(-20);
    t1.rbt_insert(99);
    t1.rbt_insert(12);
    t1.rbt_insert(30);
    t1.rbt_insert(85);
    t1.levelorder_tree_walk();
    // t1.rbt_delete(4);
    t1.rbt_delete(2);
    cout << endl;
    t1.levelorder_tree_walk();
    cout << endl;
    t1.inorder_tree_walk();
    return 0;
}