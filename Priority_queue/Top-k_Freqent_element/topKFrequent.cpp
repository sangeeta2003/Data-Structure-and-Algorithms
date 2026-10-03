class Solution {
    struct cmp{
        bool operator()(pair<int,int> &a, pair<int,int> &b){
            if(a.first != b.first){
                return a.first > b.first;
            }
            return a.second > b.second;

        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        unordered_map<int,int>f;
        for(int i =0 ; i < n ;i++){
            f[nums[i]]++;
        }
        for(auto i : f){
            int ele = i.first;
            int freq = i.second;
            pair<int,int> curr = {freq,ele};
            if(pq.size() < k){
            pq.push(curr);
            continue;
        }
        if(curr.first < pq.top().first){
            continue;
        }
        pq.pop();
        pq.push(curr);

        }
        
        
vector<int>res;
while(!pq.empty()){
    res.push_back(pq.top().second);
    pq.pop();
}
return res;
    }
};