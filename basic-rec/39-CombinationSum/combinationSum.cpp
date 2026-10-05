class Solution {
    private:
    void fun(vector<int>& candidates, int target,int idx,int n , vector<int>& diary,vector<vector<int>> &res, int sum){
        if(idx == n){
            if(sum == target){
                res.push_back(diary);

            }
            return;

        }
        // not taking
        fun(candidates,target,idx+1,n,diary,res,sum);
        // take
        if(sum + candidates[idx] <= target){
            diary.push_back(candidates[idx]);
            fun(candidates,target,idx,n,diary,res,sum + candidates[idx]);
            diary.pop_back();
            // sum -= candidates[idx];

        }

    };

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>diary;
        vector<vector<int>> res;
        int sum =0;
         fun(candidates,target,0,candidates.size(),diary,res,sum);
         return res;
    }
};