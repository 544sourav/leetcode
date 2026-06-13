class Solution {
public:
    int eat(vector<int>&piles,int s){
        int hr = 0;
        for(auto x:piles){
            hr += x/s;
            if(x%s!=0)hr+=1; 
        }
        return hr;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n =piles.size();
        int lo = 1;
        int hi = *max_element(piles.begin(),piles.end());
        int k =hi;
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            int hr = eat(piles,mid);
            // if(hr == h)return mid;
            if(hr<=h){
                k=mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return k;
    }
};