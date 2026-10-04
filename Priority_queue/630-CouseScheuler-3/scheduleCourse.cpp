class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {

        // Sort by last day
        sort(courses.begin(), courses.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        priority_queue<int> pq; // max heap
        int time = 0;

        for (auto& course : courses) {

            int duration = course[0];
            int lastDay = course[1];

            time += duration;
            pq.push(duration);

            // If deadline is exceeded,
            // remove the longest course
            if (time > lastDay) {
                time -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};