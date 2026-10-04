class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> proj;
        for(int i = 0 ; i < n ;i++){
            proj.push_back({capital[i],profits[i]});

        }
        sort(proj.begin(),proj.end());
        priority_queue<int>pq;
        int ind = 0;
        while(k--){
while(ind < n){
    if(proj[ind].first > w) break;
    pq.push(proj[ind].second);
    ind++;
}
if(pq.empty()) return w;
w = w + pq.top();
pq.pop();
        }
        return w;
    }
};