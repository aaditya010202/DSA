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
    bool isPalindrome(ListNode* head) {
        // MY SOLUTION(Only 85 passed)
        // ListNode* slow=head;
        // ListNode* fast=head;
        // if(head==NULL ) return false;
        // if(head->next==NULL) return true;
        // while(fast!=NULL && fast->next!=NULL)
        // {
        //     slow=slow->next;
        //     fast=fast->next->next;
        // }
        // if(slow->next==NULL){
        //     if(head->val==slow->val)return true;
        //     else return false;
        // }
        // ListNode* revHead=slow->next;
        // ListNode* temp=NULL;
        // while(revHead!=NULL ){
        //     ListNode* nextNode=revHead->next;
        //     revHead->next=temp;
        //     temp=revHead;
        //     revHead=nextNode;
        // }

        // slow->next=temp;

        // ListNode* orgHead=head;
        // while(temp!=NULL)
        // {
        //      if(temp->val!=orgHead->val) return false;
        //         temp=temp->next;
        //         orgHead=orgHead->next;
        //     else
        // }
        // return true;
 
        ListNode *slow = head, *fast = head;
        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != NULL && fast->next == NULL){
            slow = slow->next;
        }
        ListNode *prev = NULL;
        ListNode *temp = NULL;
        while(slow != NULL && slow->next != NULL){
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        if(slow != NULL){
            slow->next = prev;
        }
        fast = head;
        while(slow && fast){
            if(slow->val != fast->val){
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;

    }
};