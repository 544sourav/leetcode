class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        double avg = INT_MIN;
        int n = nums.size();
        int i = 0;
        int j = 0;

        for (i = 0; i < k; i++) {
            sum += nums[i];
        }
        avg = max(avg, sum / k);

        while (i < n) {
            sum -= nums[j];
            j++;
            sum += nums[i];  
            avg = max(avg, sum / k);
            i++;           
        }

        return avg;
    }
};
