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
    ListNode* sortList(ListNode* head) {
        auto itr=head;
        vector<int> v;
        while(itr) {
            v.push_back(itr->val);
            itr=itr->next;
        }
        sort(v.begin(), v.end());
        itr=head; int i=0;
        while(itr) {
            itr->val=v[i++];
            itr=itr->next;
        }
        return head;
    }
};