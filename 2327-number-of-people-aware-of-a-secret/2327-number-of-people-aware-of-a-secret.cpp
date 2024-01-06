class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>v(2001,0);
        int mod=pow(10,9)+7;
        v[1]=1;

        for(int i=1;i<=n;i++){
            for(int j=i+delay;j<i+forget;j++){
                v[j]=(v[j]+v[i])%mod;
            }
        }
        int i=0;
        long long int ans=0;

        while(forget--){
            ans=(ans+v[n-i])%mod;
            i++;
        }
     return ans;
    }
};