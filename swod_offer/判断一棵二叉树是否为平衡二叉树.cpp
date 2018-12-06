int max(int a, int b) {
    return (a > b) ? a : b;
}

int BinaryTreeDepth(TreeNode *root) {
    if (root) {
        return 1 + max(BinaryTreeDepth(root->left),
                       BinaryTreeDepth(root->right));
    }
    return 0;
}

bool IsBalanced1(TreeNode *root) {
    if (root == nullptr) return true;
    int left_depth = BinaryTreeDepth(root->left);
    int right_depth = BinaryTreeDepth(root->right);
    int diff = left_depth - right_depth;

    if (diff > 1 || diff < -1) return false;

    return IsBalanced(root->left) && IsBalanced(root->right);
}

bool IsBalanced2(TreeNode *root) {
    if (root == nullptr) return true;

    int depth;
    return IsBalancedIMPL(root, &depth);

}

bool IsBalancedIMPL(TreeNode *root, int *depth) {
    if (root == nullptr) {
        *depth = 0;
        return true;
    }

    int left, right;
    if (IsBalancedIMPL(root->left, &left) &&
        IsBalancedIMPL(root->right, &right)) {
        int diff = left - right;
        if (diff =<1 && diff >= -1){
            *depth = max(left, right) + 1;
            return true;
        }
    }

    return false;
}