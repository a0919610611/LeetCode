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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        bool first = true;
        ListNode* now = nullptr;
        ListNode* ans = nullptr;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            if (first) {
                first = false;
                now = new ListNode(0);
                ans = now;
            } else {
                now->next = new ListNode(0);
                now = now->next;
            }
            if (l1 && l2) {
                int sum = l1->val + l2->val + carry;
                now->val = sum % 10;
                carry = sum / 10;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1) {
                int sum = l1->val + carry;
                now->val = sum % 10;
                carry = sum / 10;
                l1 = l1->next;
            } else if (l2) {
                int sum = l2->val + carry;
                now->val = sum % 10;
                carry = sum / 10;
                l2 = l2->next;
            } else if (carry > 0) {
                now->val = carry;
                carry = 0;
            }
        }
        return ans;
    }
};
