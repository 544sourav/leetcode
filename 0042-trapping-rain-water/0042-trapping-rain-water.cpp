class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>mono;
        int n = height.size();
        int total =0;
        for(int i=0;i<n;i++){
            while(!mono.empty() && height[i]>height[mono.top()]){
                auto top = mono.top();
                mono.pop();
                if(mono.empty())break;
                int l = mono.top();
                int h = min(height[l],height[i])-height[top];
                total += (i-l-1)*h;
            }
            mono.push(i);
        }
        return total;
    }
};