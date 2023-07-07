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
    ListNode* middleNode(ListNode* head) {
        // OPTIMAL
        // Tortoise approach: we take 2 tortoise,
        //both at head. then 1st will move by 1 step
        //and the 2nd will move by 2 steps. when the
        //2nd finishes the node at which 1st is
        //pointing is the answer.

        if(head==NULL || head->next==NULL) return head; 
        ListNode *first=head, *second=head;
        while(second && second->next)
        {
            first=first->next;
            second=second->next->next;
        }
        return first;


        //surprisingly this took less time???...
        // int count = 0;
        // ListNode* temp = head;
        // while(temp != NULL){
        //     temp = temp->next;
        //     count++;
        // }
        
        // int len = 0;
        // count = count/2;
        // temp = head;
        // while(len < count){
        //     temp = temp->next;
        //     len++;
        // }

        // return temp;
    }
};