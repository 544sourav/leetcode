class RecentCounter {
private:
    deque<int> dq;   
public:
    RecentCounter() {
       
    }
    
    int ping(int t) {
        
        while (!dq.empty() && dq.front() < t - 3000) {
            dq.pop_front();
        }

       
        dq.push_back(t);

        return dq.size();
    }
};
