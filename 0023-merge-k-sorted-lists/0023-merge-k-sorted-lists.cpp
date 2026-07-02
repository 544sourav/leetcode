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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int K = lists.size();
        vector<int> sorted;
        priority_queue<int,vector<int>,greater<int>> sort;
        for(int i =0;i<K;i++){
            ListNode* temp = lists[i];
            while(temp){
                sort.push(temp->val);
                temp = temp->next;
            }
        }
       
        ListNode* head = new ListNode;
        ListNode*temp = head;
        while(!sort.empty()){
             ListNode* newnode = new ListNode(sort.top());
                sort.pop();
             //newnode->next = nullptr;
             temp->next = newnode;
             temp = temp->next;
        }
        return head->next;
    }
};