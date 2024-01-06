class Solution {
public:
    int solve(vector<int> &nums,int l,int r)
    {
        if(l>r) return 0;
        if(l==r) return nums[l];
        int tl=nums[l]+min(solve(nums,l+2,r),solve(nums,l+1,r-1));
        int tr=nums[r]+min(solve(nums,l,r-2),solve(nums,l+1,r-1));
        return max(tl,tr);
    }
    bool predictTheWinner(vector<int>& nums) {
        int sum=0;
        for(auto it:nums) sum+=it;
        int ans=solve(nums,0,nums.size()-1);
        int ans1=sum-ans;
        return ans>=ans1;
    }
};