class Solution {
public:
    int minMoves(vector<int>& nums) {
       int mini=INT_MAX;
       int sum=0;
        for(int i=0;i<nums.size();i++){
          mini=min(nums[i],mini);
          sum+=nums[i];
        }
        int n=nums.size();

    return (sum-n*mini);    
    }
};