/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void Traverse(struct TreeNode *Root, int *Size, int *Arr)
{
    if(Root == NULL)
    {
        return;
    }
    Traverse(Root->left, Size, Arr);
    Arr[*Size] = Root->val;
    ++(*Size);
    Traverse(Root->right, Size, Arr);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int *Arr = malloc(sizeof(int)*1000);
    Traverse(root, returnSize, Arr);
    return Arr;
}
