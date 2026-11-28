
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        priority_queue<pair<int,int>> pq;

        for(int i = 0; i < arr.size(); i++) {

            int dist = abs(arr[i] - x);

            if(pq.size() < k) {
                pq.push({dist, arr[i]});
            }
            else if(dist < pq.top().first ||
                   (dist == pq.top().first && arr[i] < pq.top().second)) {

                pq.pop();
                pq.push({dist, arr[i]});
            }
        }

        vector<int> res;

        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        sort(res.begin(), res.end());

        return res;
    }
};
