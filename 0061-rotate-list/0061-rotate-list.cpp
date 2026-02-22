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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int count =0;
        while(temp){
            count++;
            temp=temp->next;
        }
        if(count== 0 || head->next==nullptr){
            return head;
        }
        int node = k%count;
        if(node==0){
            return head;
        }
        
        temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next = head;
        int j = count - node-1;
        temp = head;
        while(j--){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};