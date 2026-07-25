class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int> mp;

        for(char c: tasks)
            mp[c]++;

        priority_queue<int> pq;

        for(auto [c,freq] : mp)
            pq.push(freq);

        queue<pair<int,int>> q; 
        

        int time = 0;

        while(!pq.empty() || !q.empty()) {

            time++;

            
            if(!pq.empty()) {

                int freq = pq.top();
                pq.pop();

                freq--;

                if(freq > 0)
                    q.push({freq,time+n});
            }


            
            if(!q.empty() && q.front().second == time) {

                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};