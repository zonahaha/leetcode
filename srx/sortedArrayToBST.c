/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* makeTree(int* nums, int start, int end){
    struct TreeNode* root;
    root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if(start<=end){
        int mid=(start+end)/2;
        root->val=nums[mid];
        root->left=makeTree(nums,start, mid-1);
        root->right=makeTree(nums, mid+1,end);
        return root;
    }
    return NULL;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    struct TreeNode* root;
    root = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    root=makeTree(nums,0, numsSize-1);
    
    return root;
}
