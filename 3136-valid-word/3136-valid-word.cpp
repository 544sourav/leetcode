class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3)
            return false;

        unordered_map<char, int> vo = {
            {'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1},
            {'A', 1}, {'E', 1}, {'I', 1}, {'O', 1}, {'U', 1}
        };

        bool isvo = false;
        bool iscon = false;

        for (char c : word) {
            if (c == '@' || c == '#' || c == '$')
                return false;

            if (isalpha(c)) {
                if (vo.count(c)) {
                    isvo = true;
                } else {
                    iscon = true;
                }
            }
        }

        return isvo && iscon ;
    }
};
