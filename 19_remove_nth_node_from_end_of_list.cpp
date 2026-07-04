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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode* fast = head;
        int i=0;
        while(i<n){
            fast = fast->next;
            i++;
        }

        ListNode* prev=NULL;
        while(fast!=NULL){
            prev=slow;
            slow =slow->next;
            fast = fast->next;
        }
        if(prev==NULL){
            ListNode* temp = head;
            head=head->next;
            delete temp;
            return head; 
        }
        prev->next = slow->next;
        slow->next=NULL;
        delete slow;
        return head;
    }
};