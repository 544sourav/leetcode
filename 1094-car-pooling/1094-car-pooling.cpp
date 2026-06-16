class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(),
             [](auto &a, auto &b) {
                 return a[1] < b[1];
             });

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        int cur = 0;

        for (auto &v : trips) {
            int passengers = v[0];
            int from = v[1];
            int to = v[2];

            while (!pq.empty() && pq.top().first <= from) {
                cur -= pq.top().second;
                pq.pop();
            }

            cur += passengers;
            if (cur > capacity) return false;

            pq.push({to, passengers});
        }

        return true;
    }
};