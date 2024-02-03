class Solution {
public:
    bool isvalidIdx(int i,int j,int r,int c){
        return (i>=0 && i<r && j>=0 && j<c);
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int r = img.size(),c=img[0].size();
        vector<vector<int>> ans(r,vector<int>(c,0));
        for(int i = 0; i<r;i++){
            for(int j = 0; j<c;j++){
                int sum = 0;
                int cnt = 0;
                if(isvalidIdx(i-1,j,r,c)){cnt++; sum+=img[i-1][j];};
                if(isvalidIdx(i-1,j-1,r,c)){cnt++; sum+=img[i-1][j-1];};
                if(isvalidIdx(i-1,j+1,r,c)){cnt++; sum+=img[i-1][j+1];};
                if(isvalidIdx(i+1,j,r,c)){cnt++; sum+=img[i+1][j];};
                if(isvalidIdx(i+1,j+1,r,c)){cnt++; sum+=img[i+1][j+1];};
                if(isvalidIdx(i+1,j-1,r,c)){cnt++; sum+=img[i+1][j-1];};
                if(isvalidIdx(i,j,r,c)){cnt++; sum+=img[i][j];};
                if(isvalidIdx(i,j-1,r,c)){cnt++; sum+=img[i][j-1];};
                if(isvalidIdx(i,j+1,r,c)){cnt++; sum+=img[i][j+1];};
                
                ans[i][j]=floor(sum/cnt);
            }
        }
        return ans;
    }
};
