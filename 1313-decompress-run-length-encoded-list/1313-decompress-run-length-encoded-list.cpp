class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
      vector<int> ans;
        int n=nums.size();
        for (int i = 0; i < n/2; i++)
        {
            int count = 0;
            count = nums[2 * i];
            while (count > 0)
            {
                ans.push_back(nums[(2*i)+1]);
                count--;
            }
        }
        return ans;
    }
};