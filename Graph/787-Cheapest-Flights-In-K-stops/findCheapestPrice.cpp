class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>res(n,1e8);
        res[src] = 0;
        for(int i = 0 ; i <= k;i++){
            vector<int>tmp = res;
            for(int j = 0 ; j < flights.size();j++){
                int s = flights[j][0];
                int d = flights[j][1];
                int w = flights[j][2];
                if(res[s] != 1e8 && tmp[d] > res[s] + w){
                    tmp[d] = res[s] + w;
                }
            }
            res  = tmp;
        }
        if(res[dst] == 1e8) return -1;
        return res[dst];
    }
};