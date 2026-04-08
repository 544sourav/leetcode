class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int res = 0;
        unordered_set<long long> st;

        auto key = [](long long a, long long b) {
            return (a + 30001) * 60001 + (b + 30001);
        };

        for (auto& o : obstacles)
            st.insert(key(o[0], o[1]));

        long long x = 0, y = 0;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int dir = 0;

        for (int c : commands) {
            if (c == -1) dir = (dir + 1) % 4;
            else if (c == -2) dir = (dir + 3) % 4;
            else {
                for (int i = 0; i < c; i++) {
                    long long nx = x + dx[dir];
                    long long ny = y + dy[dir];
                    if (st.count(key(nx, ny))) break;
                    x = nx;
                    y = ny;
                }
                res = max(res, (int)(x*x + y*y));
            }
        }

        return res;
    }
};