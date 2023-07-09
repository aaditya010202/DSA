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

        // ITERATIVE

        // if(head==NULL || head->next==NULL) return head;
        // ListNode* front=NULL;
        // ListNode* temp=NULL;
        // while(head!=NULL)
        // {
        //     temp=head;
        //     head=head->next;
        //     temp->next=front;
        //     front=temp;
        // }
        // return temp;


        // RECURSIVE

        if(head==NULL || head->next==NULL) return head;
        // ListNode* temp1=NULL;
        ListNode* temp2= reverseList(head->next);
        ListNode* headNext=head->next;
        headNext->next=head;
        head->next=NULL;
        return temp2;

        // go till the end of list and take the last node as the new head of the list now return this head in the variable temp2. Now the head points to the second last element in the list and the head->next will be the last element which is also the temp2, so now head->next->next should be equal to head(second last element) to reverse the 2 nodes and in the end we return the last node everytime which is temp2
    }
};