struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result= NULL;
    *returnSize=0;
    int length=0;
    struct TreeNode **stack= (struct TreeNode **)malloc(sizeof(struct TreeNode *));

    if(root!=NULL||length>0){
        stack = (struct TreeNode **)realloc(stack,sizeof(struct TreeNode *)*length+1);
        stack[length++]=root;
        root=root->left;
    }
    else{
        root=stack[--length];
        result[*returnSize]=root->val;
        root=root->right;
        *returnSize+=1;
    }
    return result;

}
