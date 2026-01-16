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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        while(list1!=nullptr || list2!=nullptr){
            ListNode* tmp = new ListNode(0, nullptr);
            if(head == nullptr){
                head = tmp;
                cur = head;
            }
            else {
                cur->next = tmp;
                cur = tmp;
            }
            if(list1 == nullptr){
                tmp->val = list2->val;
                list2 = list2->next;
            }
            else if(list2 == nullptr){
                tmp->val = list1->val;
                list1 = list1->next;
            }
            else if(list1->val <= list2->val){
                tmp->val = list1->val;
                list1 = list1->next;
            }
            else{
                tmp->val = list2->val;
                list2 = list2->next;
            }
        }
        return head;
    }
};