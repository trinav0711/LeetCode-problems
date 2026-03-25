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
    int pairSum(ListNode* head) {
        vector<int> v;
        for(auto itr=head; itr; itr=itr->next)
            v.push_back(itr->val);
        int ans=INT_MIN;
        for(int i=0;i<v.size()/2;++i)
            ans=max(ans, v[i]+v[v.size()-1-i]);
        return ans;
    }
};