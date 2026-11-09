
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        set<int> available;

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;

        vector<int> count(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            // Step 1: Release servers that have completed their requests
            while (!busy.empty() && busy.top().first <= arrival[i]) {

                int server = busy.top().second;

                available.insert(server);

                busy.pop();
            }

            // Step 2: If all servers are busy, drop the request
            if (available.empty()) {
                continue;
            }

            // Step 3: Find preferred server
            int preferred = i % k;

            auto it = available.lower_bound(preferred);

            // Step 4: Wrap around if necessary
            if (it == available.end()) {
                it = available.begin();
            }

            // Step 5: Assign request
            int server = *it;

            available.erase(it);

            count[server]++;

            // Step 6: Store server's completion time
            busy.push({
                (long long)arrival[i] + load[i],
                server
            });
        }

        // Step 7: Find maximum requests handled
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {

            if (count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
