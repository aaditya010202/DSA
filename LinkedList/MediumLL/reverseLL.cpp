// leetcode

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
    ListNode* reverseList(ListNode* head) {
        // Node* temp=head;
        if(head==NULL || head->next==NULL) return head;
        ListNode* front=NULL;
        ListNode* temp=NULL;
        while(head!=NULL)
        {
            temp=head;
            head=head->next;
            temp->next=front;
            front=temp;
        }
        return temp;
    }
};