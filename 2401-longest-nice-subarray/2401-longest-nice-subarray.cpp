class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int j=0;
        int i=1;
        int lul = nums[0];
        int ans = 1;
        int cnt = 0;
        while(i<nums.size()){
            while(j<=i&&(nums[i]&lul)){
                lul^=nums[j++];
                ans=max(ans,i-j+1);
            }
            lul|=nums[i];
            ans=max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};