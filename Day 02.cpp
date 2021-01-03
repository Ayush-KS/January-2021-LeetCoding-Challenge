// Find a Corresponding Node of a Binary Tree in a Clone of That Tree

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(target == original)
            return cloned;
        if(!original)
            return NULL;
        TreeNode* left = getTargetCopy(original -> left, cloned -> left, target);
        return left == NULL ? getTargetCopy(original -> right, cloned -> right, target) : left;
    }
};