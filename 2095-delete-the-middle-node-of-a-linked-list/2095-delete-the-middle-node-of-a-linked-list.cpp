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
    ListNode* deleteMiddle(ListNode* head) {
        int n=0;
        auto itr=head;
        while(itr) {
            n++;
            itr=itr->next;
        }
        n/=2;
        if(!n)
            return nullptr;
        int cur=0;
        itr=head;
        ListNode* prev=nullptr;
        while(cur<n) {
            cur++;
            prev=itr;
            itr=itr->next;
        }
        prev->next=itr->next;
        return head;
    }
};