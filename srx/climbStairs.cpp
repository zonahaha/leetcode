class Solution {
public:
    int climbStairs(int n) {
        if(n==1)return 1;
        else if(n==2)return 2;
        vector<int> res;
        res.push_back(0);
        res.push_back(1);
        res.push_back(2); 
        int i=3;       
        while(i<=n){
            res.push_back(res[i-1]+res[i-2]);
            i++;
        }
        return res[res.size()-1]; 
    }
};
