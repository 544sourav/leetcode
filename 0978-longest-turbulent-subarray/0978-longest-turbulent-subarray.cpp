class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        string last = " ";
        int i = 0;
        int ans = 1;

        for (int j = 1; j < arr.size(); j++) {

            if (last == " ") {
                if (arr[j - 1] > arr[j])
                    last = ">";
                else if (arr[j - 1] < arr[j])
                    last = "<";
                else {
                    i = j;
                }
            }

            else if (arr[j - 1] > arr[j]) {
                if (last == "<")
                    last = ">";
                else {
                    ans = max(ans, j - i);
                    i = j - 1;
                }
            }

            else if (arr[j - 1] < arr[j]) {
                if (last == ">")
                    last = "<";
                else {
                    ans = max(ans, j - i);
                    i = j - 1;
                }
            }

            else {
                last = " ";
                ans = max(ans, j - i);
                i = j;
            }
        }

        ans = max(ans, (int)arr.size() - i);
        return ans;
    }
};