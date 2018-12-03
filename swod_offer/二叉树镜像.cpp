/*遍历二叉树，交换左右子树*/

void BinaryTreeMirror(TreeNode *pRoot) {
    if (pRoot) {
        TreeNode *pTemp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = pTemp;

        BinaryTreeMirror(pRoot->left);
        BinaryTreeMirror(pRoot->right);
    }
}