class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    if(nums.empty())
        return false;
    int elements = *max_element(nums.begin(), nums.end());
    int minNum = *min_element(nums.begin(), nums.end());
        if(minNum < 0)
            elements -= minNum;
    vector<int> dups(elements + 1, 0);
    for(int i = 0; i < nums.size(); i++)
        dups[nums[i] + (-minNum)]+= 1;
    
    for(int i = 0; i < dups.size(); i++)
        if(dups[i] > 1)
            return true;
    return false;
    }
};