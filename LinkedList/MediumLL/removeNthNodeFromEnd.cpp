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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start=new ListNode();
        start->next=head;
        ListNode* fast=start;
        ListNode* slow=start;

        for(int i=1;i<=n;i++)
        {
            fast=fast->next;
        }

        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }

        slow->next=slow->next->next;
        return start->next;

        // MY CODE(error)
        // ListNode* prev=NULL;
        // ListNode* temp=NULL;
        // while(head!=NULL){
        //     temp=head->next;
        //     head->next=prev;
        //     prev=head;
        //     head=temp;
        // }
        // int count=1;

        // ListNode* newHead=prev;
        // while(count<n)
        // {                cout<<prev->val;

        //     prev=prev->next;
        //     count++;
        // }
        // ListNode* del=prev->next;
        // prev->next=del->next;
        // del->next=NULL;

        // temp=NULL;
        // prev=NULL;
        // while(newHead!=NULL)
        // {
        //     temp=newHead->next;
        //     newHead->next=prev;
        //     prev=newHead;
        //     newHead=temp;
        // }
        // return prev;
    }
};