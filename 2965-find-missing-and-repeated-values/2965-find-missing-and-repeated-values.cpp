class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        map<int,int> mp;
        for(auto &i: grid){
            for(auto &j: i){
                mp[j]++;
            }
        }
        vector<int> ans(2,0);
        for(int i=1; i<=n*m; i++){
            if(mp[i]==0){
                ans[1]=i;
            }
            if(mp[i]==2){
                ans[0]=i;
            }
        }
        return ans;
    }
};