unordered_map<int,int>dp;
int fun(int n){
    if(n == 0 || n == 1) return n;
    if(dp.find(n) != dp.end()) return dp[n];
    int a1 = fun(n-1);
    int a2 = fun(n-2);
    int and = a1 + a2;
    dp[n] = ans;
    return ans;
}