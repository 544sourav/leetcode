class Solution {
public:
    int maximumRobots(vector<int>& charge, vector<int>& run, long long budget) {

        int n = charge.size();

        deque<int> dq; 

        long long sum = 0;
        int ans = 0;
        int left = 0;

        for(int right = 0; right < n; right++){

            while(!dq.empty() && charge[dq.back()] <= charge[right]){
                dq.pop_back();
            }

            dq.push_back(right);

            sum += run[right];


            while(left <= right && 
                 charge[dq.front()] + 
                 (long long)(right-left+1)*sum > budget){

                if(dq.front() == left){
                    dq.pop_front();
                }

                sum -= run[left];
                left++;
            }


            ans = max(ans, right-left+1);
        }

        return ans;
    }
};