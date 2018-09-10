class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int m=pow(2.0,(double)n);
        vector<vector<int>> res(m);
        for(int i=0;i<m;i++){
            for(int j=1;j<=n;j++){
                if(1&(i>>(j-1)))res[i].push_back(nums[j-1]);//用二进制判断每种状态，嘻嘻嘻嘻，100%
            }
        }
        return res;
    }
};
