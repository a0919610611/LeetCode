/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* big = new ListNode(0);
        ListNode *small2 = small;
        ListNode *big2 = big;
        while(head){
            if(head->val >= x){
                big->next= head;
                big = big->next;
            }else {
                small->next = head;
                small = small->next;
            }
            head = head->next;
        }
        big->next = nullptr;
        small->next = big2->next;
        return small2->next;
    }
};
