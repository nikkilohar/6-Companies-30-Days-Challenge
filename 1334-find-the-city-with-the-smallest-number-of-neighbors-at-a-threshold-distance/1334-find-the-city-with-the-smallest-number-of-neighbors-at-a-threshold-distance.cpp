class Solution {
public:
  vector<pair<int,int>>adj[101];
    const int INF=1e9;
    int  find_ans(int src,int n,int dis)
    {
        vector<int>distance(n,INF);
        distance[src]=0;
        set<pair<int,int>>s;
        s.insert({0,src});
        while(!s.empty()){
            auto p=*s.begin();
            s.erase(s.begin());
            int node=p.second;
            int d=p.first;
            for(auto x:adj[node]){
                int nbr=x.first;
                int w=x.second;
                if(distance[nbr]>w+d){
                    auto p=s.find({distance[nbr],nbr});
                    if(p!=s.end())s.erase(p);
                    distance[nbr]=w+d;
                    s.insert({w+d,nbr});
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i!=src and distance[i]<=dis){
                cnt++;
            }
        }
        return cnt;   
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for(int i=0;i<n;i++){
            adj[i].clear();
        }
        for(auto x:edges){
            int  u=x[0];
            int v=x[1];
            int w=x[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            int cnt=find_ans(i,n,distanceThreshold);
            vec.push_back({cnt,i});
        }
        sort(vec.begin(),vec.end());
        vector<int>ans;
        int l=vec[0].first;
        for(int i=0;i<vec.size();i++){
            if(vec[i].first==l){
                ans.push_back(vec[i].second);
            }
        }
        sort(ans.begin(),ans.end());
        return ans.back();
        
    }
};