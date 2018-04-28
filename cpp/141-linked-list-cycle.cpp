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
    bool hasCycle(ListNode *head) {
        ListNode * head1 , *head2;
        head1 = head2 = head;
        while(head!=NULL){
            head1=head1->next;
            if(head2==NULL || head2->next==NULL) return false;
            head2=head2->next->next;
            if(head1==head2) return true;
        }
        return false;
    }
};
