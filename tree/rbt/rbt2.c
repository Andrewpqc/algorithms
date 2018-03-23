#include <stdlib.h>
#include <stdio.h>

#define BLACK 1
#define RED 0

typedef struct rb_node{
    struct rb_node *right;
    struct rb_node *left;
    struct rb_node *parent;
    int key;
    int color;
} RB_NODE;

typedef struct rb_tree{
    struct rb_node *root;
    struct rb_node *nil;
} RB_TREE;

RB_NODE *node_init(RB_TREE *T)
{
    RB_NODE *node;

    node = (RB_NODE *)malloc(sizeof(RB_NODE));
    node->color = BLACK;
    node->key = 0;
    node->right = node->left = node->parent = T->nil;

    return (node);
}

RB_TREE *tree_init(void)
{
    RB_TREE *T;

    T = (RB_TREE *)malloc(sizeof(RB_TREE));
    T->nil = (RB_NODE *)malloc(sizeof(RB_NODE));
    T->nil->color = BLACK;
    T->nil->parent = T->nil->left = T->nil->right = T->nil;

    T->root = T->nil;

    return (T);
}

void node_destory(RB_TREE *T, RB_NODE *node)
{
    if (node != T->nil)
    {
        node_destory(T, node->left);
        node_destory(T, node->right);
        free(node);
    }
}

void tree_destory(RB_TREE *T)
{
    free(T->nil);
    free(T);
}

void inorder_tree_walk(RB_TREE *T, RB_NODE *x)
{
    if (x != T->nil)
    {
        inorder_tree_walk(T, x->left);
        printf("%d ", x->key);
        inorder_tree_walk(T, x->right);
    }
}

RB_NODE *rbtree_minimum(RB_TREE *T, RB_NODE *x)
{
    /*
     * 二叉搜索树性质保证了tree_minimum是正确的
     */
    while (x->left != T->nil)
        x = x->left;

    return (x);
}

RB_NODE *rbtree_maximum(RB_TREE *T, RB_NODE *x)
{
    /*
     * 与tree_minimum是对称的
     */
    while (x->right != T->nil)
        x = x->right;

    return (x);
}

RB_NODE *rbtree_search(RB_TREE *T, RB_NODE *x, int k)
{
    if (x == T->nil || k == x->key)
        return (x);
    if (k < x->key)
        return (rbtree_search(T, x->left, k));
    else
        return (rbtree_search(T, x->right, k));
}

RB_NODE *rbiterative_tree_search(RB_TREE *T, RB_NODE *x, int k)
{
    /*
     * 对于大多数计算机，采用while循环
     * 来展开递归，用一种迭代方式重新
     * 这个过程，运行的效率要比递归高
     * 的多。
     */
    while (x != T->nil && k != x->key)
    {
        if (k < x->key)
            x = x->left;
        else
            x = x->right;
    }

    return (x);
}

RB_NODE *rbtree_successor(RB_TREE *T, RB_NODE *x)
{
    /*
     * 查找一个节点的后继
     *
     * case1: 如果结点x的右子树非空，
     * 那么x的后继恰是x右子树中的最左结点。
     *
     * case2:如果结点x的右子树为空,并有一个后继y，
     * 那么y就是x的有左孩子的最底层祖先，并且它也是
     * x的一个祖先
     */
    RB_NODE *y;

    y = node_init(T);

    if (x->right != T->nil)
        return rbtree_minimum(T, x->right);

    y = x->parent;
    while (y != T->nil && x == y->right)
    {
        x = y;
        y = y->parent;
    }

    return (y);
}

RB_NODE *rbtree_predecessor(RB_TREE *T, RB_NODE *x)
{
    /*
     * 查找先驱，与tree_successor对称
     */
    RB_NODE *y;

    y = node_init(T);

    if (x->left != T->nil)
        return rbtree_maximum(T, x->left);

    y = x->parent;
    while (y != T->nil && x == y->left)
    {
        x = y;
        y = y->parent;
    }

    return (y);
}

void left_rotate(RB_TREE *T, RB_NODE *x)
{
    RB_NODE *y;

    y = x->right;       //set y
    x->right = y->left; //turn y's left subtree into x's right subtree
    if (y->left != T->nil)
        y->left->parent = x;
    y->parent = x->parent; //link x's parent to y
    if (x->parent == T->nil)
        T->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x; //put x on y's left
    x->parent = y;
}

void right_rotate(RB_TREE *T, RB_NODE *y)
{
    RB_NODE *x;

    x = y->left;        //set x
    y->left = x->right; //turn x's left subtree into y's left subtree
    if (x->right != T->nil)
        x->right->parent = y;
    x->parent = y->parent; //link y's parent to x
    if (y->parent == T->nil)
        T->root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;
    x->right = y; //put y on x's left
    y->parent = x;
}

void rb_insert_fixup(RB_TREE *T, RB_NODE *z)
{
    RB_NODE *y;

    while (z->parent->color == RED)
    {
        if (z->parent->parent != T->nil && z->parent == z->parent->parent->left)
        {
            y = z->parent->parent->right;
            if (y->color == RED)
            {
                z->parent->color = BLACK;       //case 1
                y->color = BLACK;               //case 1
                z->parent->parent->color = RED; //case 1
                z = z->parent->parent;          //case 1
                continue;                       //case 1
            }
            else if (z == z->parent->right)
            {
                z = z->parent;     //case 2
                left_rotate(T, z); //case 2
            }
            z->parent->color = BLACK;           //case 3
            z->parent->parent->color = RED;     //case 3
            right_rotate(T, z->parent->parent); //case 3
        }
        else if (z->parent->parent != T->nil)
        {
            y = z->parent->parent->left;
            if (y->color == RED)
            {
                z->parent->color = BLACK;       //case 1
                y->color = BLACK;               //case 1
                z->parent->parent->color = RED; //case 1
                z = z->parent->parent;          //case 1
                continue;                       //case 1
            }
            else if (z == z->parent->left)
            {
                z = z->parent;      //case 2
                right_rotate(T, z); //case 2
            }
            z->parent->color = BLACK;          //case 3
            z->parent->parent->color = RED;    //case 3
            left_rotate(T, z->parent->parent); //case 3
        }
        T->root->color = BLACK;
    }
}

void rb_insert(RB_TREE *T, RB_NODE *z)
{
    RB_NODE *x, *y;

    y = T->nil;
    x = T->root;
    while (x != T->nil)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y == T->nil)
        T->root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
    z->left = T->nil;
    z->right = T->nil;
    z->color = RED;
    rb_insert_fixup(T, z);
}

void rb_transplant(RB_TREE *T, RB_NODE *u, RB_NODE *v)
{
    if (u->parent == T->nil)
        T->root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    v->parent = u->parent;
}

void rb_delete_fixup(RB_TREE *T, RB_NODE *x)
{
    RB_NODE *w;

    while (x != T->root && x->color == BLACK)
    {
        if (x == x->parent->left)
        {
            w = x->parent->right;
            if (w->color == RED)
            {
                w->color = BLACK;          //case 1
                x->parent->color = RED;    //case 1
                left_rotate(T, x->parent); //case 1
                w = x->parent->right;      //case 1
            }

            if (w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED; //case 2
                x = x->parent;  //case 2
            }
            else if (w->right->color == BLACK)
            {
                w->left->color = BLACK; //case 3
                w->color = RED;         //case 3
                right_rotate(T, w);     //case 3
                w = x->parent->right;   //case 3
            }
            w->color = x->parent->color; //case 4
            x->parent->color = BLACK;    //case 4
            w->right->color = BLACK;     //case 4
            left_rotate(T, x->parent);   //case 4
            x = T->root;                 //case 4
        }
        else
        {
            if (x == x->parent->right)
            {
                w = x->parent->left;
                if (w->color == RED)
                {
                    w->color = BLACK;
                    x->parent->color = RED;
                    right_rotate(T, x->parent);
                    w = x->parent->left;
                }

                if (w->right->color == BLACK && w->left->color == BLACK)
                {
                    w->color = RED;
                    x = x->parent;
                }
                else if (w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    left_rotate(T, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                right_rotate(T, x->parent);
                x = T->root;
            }
        }
    }
    x->color = BLACK;
}

void rb_delete(RB_TREE *T, RB_NODE *z)
{
    RB_NODE *x, *y;
    int y_orginal_color;

    y = z;
    y_orginal_color = y->color;
    if (z->left == T->nil)
    {
        x = z->right;
        rb_transplant(T, z, z->right);
    }
    else if (z->right == T->nil)
    {
        x = z->left;
        rb_transplant(T, z, z->left);
    }
    else
    {
        y = rbtree_minimum(T, z->right);
        y_orginal_color = y->color;
        x = y->right;
        if (y->parent == z)
            x->parent = y;
        else
        {
            rb_transplant(T, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        rb_transplant(T, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if (y_orginal_color == BLACK)
        rb_delete_fixup(T, x);
}

void node_insert(RB_TREE *T, int key)
{
    RB_NODE *node;

    node = node_init(T);
    node->key = key;

    rb_insert(T, node);
}

void node_delete(RB_TREE *T, int key)
{
    RB_NODE *node;

    if ((node = rbtree_search(T, T->root, key)) != T->nil)
    {
        rb_delete(T, node);
        free(node);
    }
    else
        fprintf(stderr, "can't find %d\n", key);
}

int main(void)
{
    //int         i;
    RB_TREE *T;

    T = tree_init();

    node_insert(T, 23);
    node_insert(T, 94);
    node_insert(T, 32);
    node_insert(T, 84);
    node_insert(T, 12);
    node_insert(T, 8);
    node_insert(T, 82);
    node_insert(T, 31);
    node_insert(T, 59);
    node_insert(T, 41);
    node_insert(T, 73);

    //for ( i = 0 ; i < 1000 ; i++ ) {
    //    key = rand() % 1000;
    //    node_insert(T, key);
    //}

    inorder_tree_walk(T, T->root);
    printf("\n");

    node_delete(T, 32);
    node_delete(T, 8);
    node_delete(T, 4);

    printf("after delete 32, 8, 4:\n");
    inorder_tree_walk(T, T->root);
    printf("\n");

    printf("sucessor of 23 is %d\n", rbtree_successor(T, rbtree_search(T, T->root, 23))->key);
    printf("predecessor of 84 is %d\n", rbtree_predecessor(T, rbtree_search(T, T->root, 84))->key);
    printf("the maximun is %d\n", rbtree_maximum(T, T->root)->key);
    printf("the minimum is %d\n", rbtree_minimum(T, T->root)->key);

    node_destory(T, T->root);
    tree_destory(T);

    exit(0);
}