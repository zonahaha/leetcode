int maxDepth(struct TreeNode* root){
    int l=1;
    int r=1;
    int count=0;
    if(root){
        if(root->left)l=1+maxDepth(root->left);
        if(root->right)r=1+maxDepth(root->right);
        count=l>r?l:r;
    }
    return count;
}
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if(!root)return NULL;
    int depth=*returnSize=maxDepth(root);
    int **res=calloc(depth,sizeof(int*));
    *columnSizes=calloc(depth,sizeof(int));
    
    struct TreeNode* queue[5000];//队列的每个元素都是一个树节点，有各自的left，right，val
	int front=0;
    int rear=0;
	int size=depth-1;
    int cur_size=1;
	int next_size=0;
    queue[rear++]=root;
    struct TreeNode* temp=NULL;
	while(front<rear){
		res[size]=(int*)malloc(sizeof(int)*2000);
			for(int i=0;i<cur_size&&front<rear;i++){//用cur_size标记一层有多少个节点，然后逐层访问这些节点的子节点，再按层添加到queue中去
				temp=queue[front++];
				res[size][i]=temp->val;//res用来按层存储树节点值域
				if(temp->left){        	
					queue[rear++]=temp->left;//queue用来存储按顺序即将遍历的树节点
					next_size++;
				}
				if(temp->right){
					queue[rear++]=temp->right;
					next_size++;
				}
			}
				(*columnSizes)[size--]=cur_size;
				cur_size=next_size;
				if(cur_size==0)break;
				next_size=0;	
	}
	return res;		
}
