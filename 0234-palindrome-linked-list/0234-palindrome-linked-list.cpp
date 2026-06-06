/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int>val;
        ListNode* temp = head;
        while(temp!=nullptr){
            // cout<<temp->val<<" ";
            val.push_back(temp->val);
            temp = temp->next;
        }
        int i = 0;
        int j = val.size()-1;
        while(i<j){
            // cout<<val[i] << " "<<val[j]<<endl;
            if(val[i]!=val[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};