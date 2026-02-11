class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s= *min_element(bloomDay.begin(),bloomDay.end());
        int e=*max_element(bloomDay.begin(),bloomDay.end());
        
        int n =bloomDay.size();
        if((long)m*k>n) return -1;
        int mindays =INT_MAX;
        while(s<=e){
            int mid = s+(e-s)/2;
          
            int cnt=0;
            int total=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    
                    cnt++;
                    if(cnt==k){
                        total++;
                        cnt=0;
                    }
                }
                else{
                   
                    cnt=0;
                }
            }
            if(total>=m){
                mindays = min(mid,mindays);
                e = mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return mindays==INT_MAX ?s:mindays;
    }
};