class Solution {
public:

    void get(vector<vector<int>>&v, vector<int>temp, vector<int>candidates, int index, int sum, int target){
        if(index >= candidates.size() || sum > target)return; //Base Case

        if(sum == target){  //when condition meet
            v.push_back(temp);
            return;
        }

        //Including
        sum += candidates[index];
        temp.push_back(candidates[index]);
        get(v, temp, candidates, index, sum, target); 

        //Excluding and Backtracking
        sum -= candidates[index];
        temp.pop_back();
        get(v, temp, candidates, index+1, sum, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        get(ans, temp, candidates, 0, 0, target);
        return ans;
    }
};