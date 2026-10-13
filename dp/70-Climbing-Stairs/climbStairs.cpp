class Solution {
    int fun(int n, int i,unordered_map<int,int>& dp){
        
        
        if(i == n) return 1;
        if(i > n) return 0;
        if(dp.find(i) != dp.end()) return dp[i];
        int a1 = fun(n,i+1,dp);
         int a2 = fun(n,i+2,dp);
         int ans = a1 + a2;
         dp[i] = ans;
         return ans ;
         
    }
public:
    int climbStairs(int n) {
        unordered_map<int,int>dp;
        return fun(n,0,dp);

        
    }
};