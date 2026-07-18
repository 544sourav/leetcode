class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<string> st;

        for (int i = n - 1; i >= 0; i--) {

            if (s[i] == ']') {
                st.push("]");
            }

            else if (s[i] == '[') {
                string temp = "";

                while (!st.empty() && st.top() != "]") {
                    temp += st.top();
                    st.pop();
                }

                st.pop();             
                st.push(temp);
            }

            else if (isdigit(s[i])) {
                int k = 0;
                int place = 1;

            
                while (i >= 0 && isdigit(s[i])) {
                    k += (s[i] - '0') * place;
                    place *= 10;
                    i--;
                }
                i++;                  

                string rep = st.top();
                st.pop();

                string temp = "";
                while (k--) {
                    temp += rep;
                }

                st.push(temp);
            }

            else {
                st.push(string(1, s[i]));
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};