class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
         double ans = 0;
        vector<pair<double,int>> items;
        for(int i = 0 ; i < n ;i++){
            double ratio = (double) val[i] / wt[i];
            items.push_back({ratio,i});
        }
            sort(items.rbegin(),items.rend());
           
            for(auto item:items){
                int i = item.second;
                if(capacity >= wt[i]){
                    ans += val[i];
                    capacity -= wt[i];
                }else{
                    ans += item.first * capacity;
                    break;
                }
            }
        
        return ans;
    }
};
