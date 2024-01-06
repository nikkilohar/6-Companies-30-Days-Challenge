class Solution {
public:
    int dp[1001][1001];
    int mod = 1e9+7;
    int helper(int diff,int k)
    {
        if(diff>=k)
            return diff==k;
        if(dp[diff][k]!=-1)
            return dp[diff][k];
        return dp[diff][k]=helper(diff+1,k-1)%mod+helper(abs(diff-1),k-1)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
        return helper(abs(startPos-endPos),k)%mod;
    }
};