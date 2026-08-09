class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indexes = {0, 0};
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i; j < nums.size(); j++)
            {
                if(i == j)
                    continue;
                if(nums[i] + nums[j] == target){
                    if(i < j)
                    {
                        indexes[0] = i;
                        indexes[1] = j;
                    }
                    else
                    {
                        indexes[0] = i;
                        indexes[1] = j;
                    }
                }
            }
        }
        return indexes;
    }
};
