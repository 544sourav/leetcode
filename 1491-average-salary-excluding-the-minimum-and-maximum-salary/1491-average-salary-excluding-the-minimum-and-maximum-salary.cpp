class Solution {
public:
    double average(vector<int>& salary) {
        int sum = accumulate(salary.begin(),salary.end(),0);
        int maxi = *max_element(salary.begin(),salary.end());
        int mini = *min_element(salary.begin(),salary.end());
        sum  = sum -(maxi+mini);
        int n = salary.size();

        double avg = double(sum)/double(n-2);
        
        
        return avg;
    }
};