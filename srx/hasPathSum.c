/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool addSum(struct TreeNode* root,int sum){
    bool res=false;
    if(root->left){
        root->left->val+=root->val;
        res=addSum(root->left,sum);
        if(res==true)return true;
    }
    if(root->right){
        root->right->val+=root->val;
        res=addSum(root->right,sum);
        if(res==true)return true;
    }
    if(!root->left&&!root->right){
        if(root->val==sum)return true;
    }      
    return res;
} 
bool hasPathSum(struct TreeNode* root, int sum) {
    if(!root)return false; 
    return addSum(root,sum);
}
////////////////////////////////////////////////////////////////////////另一种写法,不需要两个函数
bool hasPathSum(struct TreeNode* root,int sum){
    if(!root)return false;
    if(!root->left&&!root->right){
        return sum==root->val;//还能这样写，真厉害啊
    }return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
}
////////////////////////////////////////////////////////////////////////////
好吧，我本来考虑的是用数组存储叶子节点的终值，然后最后查找是否等于sum，结果可以run
但是submit failure，因为数组想要定义成全局变量，submit就会出问题，看了答案，其实
不用存储下来，每次得到一个叶子节点的sum结果，直接和sum对比一下一下就可以了，我的反
而麻烦了，后来又在想对比如果相等之后又怎么直接结束递归，避免继续递归带来额外的时间，
想用函数间的跳转，setjmp函数，可是run起来声明文件好像也有问题，，最后决定不跳转，
写了第一种，第二种是人家100%的答案，return sum==root->val 和sum-root->val这两句真的是精髓啊
