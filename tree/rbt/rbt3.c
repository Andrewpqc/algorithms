#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _rbnode
{
    struct _rbnode *left;
    struct _rbnode *right;
    struct _rbnode *parent;
    int key, color;
} node;
node nilnode = {.left = NULL, .right = NULL, .parent = NULL, .color = 0, .key = 0};
node *nil = &nilnode;
#define COLOR(x) ((x)->color)
void left_rotate(node **T, node *x)
{
    node *y = x->right;
    node *w = x->parent;
    if (w == nil)
    {
        *T = y;
    }
    else if (x == w->left)
    {
        w->left = y;
    }
    else
    {
        w->right = y;
    }
    x->right = y->left;
    y->left->parent = x;
    y->parent = w;
    y->left = x;
    x->parent = y;
}
void right_rotate(node **T, node *x)
{
    node *y = x->left;
    node *w = x->parent;
    if (w == nil)
    {
        *T = y;
    }
    else if (x == w->left)
    {
        w->left = y;
    }
    else
    {
        w->right = y;
    }
    x->left = y->right;
    y->right->parent = x;
    y->right = x;
    y->parent = x->parent;
    x->parent = y;
}
void rb_insert_fixup(node **T, node *x)
{
    while (COLOR(x->parent))
    {
        if (x->parent == x->parent->parent->left)
        {
            node *y = x->parent->parent->right;
            if (COLOR(y))
            {
                x->parent->color = 0;
                y->color = 0;
                x->parent->parent->color = 1;
                x = x->parent->parent;
            }
            else
            {
                if (x == x->parent->right)
                {
                    x = x->parent;
                    left_rotate(T, x);
                }
                x->parent->color = 0;
                x->parent->parent->color = 1;
                right_rotate(T, x->parent->parent);
            }
        }
        else
        {
            node *y = x->parent->parent->left;
            if (COLOR(y))
            {
                x->parent->color = 0;
                y->color = 0;
                x->parent->parent->color = 1;
                x = x->parent->parent;
            }
            else
            {
                if (x == x->parent->left)
                {
                    x = x->parent;
                    right_rotate(T, x);
                }
                x->parent->color = 0;
                x->parent->parent->color = 1;
                left_rotate(T, x->parent->parent);
            }
        }
    }
    (*T)->color = 0;
}
void rb_insert(node **T, node *x)
{
    node *y = nil;
    node *z = *T;
    while (z != nil)
    {
        y = z;
        if (x->key < z->key)
        {
            z = z->left;
        }
        else
        {
            z = z->right;
        }
    }
    x->parent = y;
    if (y == nil)
    {
        *T = x;
    }
    else if (x->key < y->key)
    {
        y->left = x;
    }
    else
    {
        y->right = x;
    }
    x->left = nil;
    x->right = nil;
    x->color = 1;
    rb_insert_fixup(T, x);
}
node *tree_minimum(node *z)
{
    while (z->left != nil)
    {
        z = z->left;
    }
    return z;
}
node *tree_successor(node *z)
{
    if (z->right != nil)
    {
        return tree_minimum(z->right);
    }
    node *y = z->parent;
    while (y != nil && z == y->right)
    {
        z = y;
        y = y->parent;
    }
    return y;
}
void rb_delete_fixup(node **T, node *x)
{
    while (x != *T && COLOR(x) == 0)
    {
        if (x == x->parent->left)
        {
            node *w = x->parent->right;
            if (COLOR(w))
            {
                w->color = 0;
                x->parent->color = 1;
                left_rotate(T, x->parent);
                w = x->parent->right;
            }
            if (COLOR(w->left) == 0 && COLOR(w->right) == 0)
            {
                w->color = 1;
                x = x->parent;
            }
            else
            {
                if (COLOR(w->right) == 0)
                {
                    w->left->color = 0;
                    w->color = 1;
                    right_rotate(T, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = 0;
                w->right->color = 0;
                left_rotate(T, x->parent);
                x = *T;
            }
        }
        else
        {
            node *w = x->parent->left;
            if (COLOR(w))
            {
                w->color = 0;
                x->parent->color = 1;
                right_rotate(T, x->parent);
                w = x->parent->left;
            }
            if (COLOR(w->left) == 0 && COLOR(w->right) == 0)
            {
                w->color = 1;
                x = x->parent;
            }
            else
            {
                if (COLOR(w->left) == 0)
                {
                    w->right->color = 0;
                    w->color = 1;
                    left_rotate(T, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = 0;
                w->left->color = 0;
                right_rotate(T, x->parent);
                x = *T;
            }
        }
    }
    x->color = 0;
}
node *rb_delete(node **T, node *z)
{
    node *y;
    node *x;
    if (z->left == nil || z->right == nil)
    {
        y = z;
    }
    else
    {
        y = tree_successor(z);
    }
    if (y->left != nil)
    {
        x = y->left;
    }
    else
    {
        x = y->right;
    }
    x->parent = y->parent;
    if (y->parent == nil)
    {
        *T = x;
    }
    else if (y == y->parent->left)
    {
        y->parent->left = x;
    }
    else
    {
        y->parent->right = x;
    }
    if (y != z)
    {
        z->key = y->key;
    }
    if (y->color == 0)
    {
        rb_delete_fixup(T, x);
    }
    return y;
}
void print_tree(node *t)
{
    if (t == nil)
        return;
    print_tree(t->left);
    printf("%d,%d ", t->key, t->color);
    print_tree(t->right);
}
node *RBT = &nilnode;
int main(void)
{
    int keys[] = {5, 4, 3, 9, 7};
    int i;
    node *a;
    node *b;
    for (i = 0; i < 5; i++)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->key = keys[i];
        rb_insert(&RBT, temp);
        if (keys[i] == 4)
            a = temp;
    }
    printf("R: %d\n", RBT->key);
    print_tree(RBT);
    printf("\n");
    b = rb_delete(&RBT, a);
    free(b);
    printf("R: %d\n", RBT->key);
    print_tree(RBT);
}
