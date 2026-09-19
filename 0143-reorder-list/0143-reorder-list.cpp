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
    void reorderList(ListNode* head) {
        ListNode *slow=head, *fast=head;
        while(slow && fast->next && fast->next->next) {
            slow=slow->next; fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=nullptr;
        {
            ListNode* prev=nullptr;
            while(fast) {
                auto tmp=fast->next;
                fast->next=prev;
                prev=fast;
                fast=tmp;
            }
            fast=prev;
        }
        slow=head;
        while(slow!=nullptr && fast!=nullptr) {
            ListNode* tmp=slow->next;
            slow->next=fast;
            slow=tmp;
            tmp=fast->next;
            fast->next=slow;
            fast=tmp;
        }
    }
};