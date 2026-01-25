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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int ctr;
        vector<int>v;
        ListNode *cur=head;
        while(cur) {
            vector<int>tmp;
            ctr=0;
            while(cur && ctr<k) {
                tmp.push_back(cur->val);
                cur=cur->next;
                ctr++;
            }
            if(ctr>=k)
                reverse(tmp.begin(), tmp.end());
            for(int x:tmp)
                v.push_back(x);
        }
        for(cur=head, ctr=0;cur && ctr<v.size();cur=cur->next)
            cur->val=v[ctr++];
        return head;
    }
};