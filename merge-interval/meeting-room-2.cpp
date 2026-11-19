class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int room = 0;
        int res = 0;
        int i = 0;
        int j = 0;
        sort(start.begin(), start.end());
               sort(end.begin(), end.end());

        while(i < start.size()){
            if(start[i] < end[j]){
                room++;
                i++;
                res = max(res,room);
            }else{
                room--;
                j++;
            }
        }
        return res;
    }
};
