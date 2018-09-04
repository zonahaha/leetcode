class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;//无序的 快速的检索 达到的是更快的访问 但是子集的范围迭代效率低
                                   //unordered_map中的元素没有按照它们的键值或映射值的任何顺序排序，
                                   //而是根据它们的散列值组织成桶以允许通过它们的键值直接快速访问单个元素（具有常数平均时间复杂度）。
        for(int i=0;i<nums.size();i++){
            if(map[nums[i]]&&i+1-map[nums[i]]<=k)return true;
            map[nums[i]]=i+1;//i有可能为0
        }
        return false;
    }
};
