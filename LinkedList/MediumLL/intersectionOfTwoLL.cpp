// leetcode
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // BEST OPTIMAL APPROACH 

        // if(headA==NULL || headB==NULL) return NULL;
        // ListNode* d1=headA;
        // ListNode* d2=headB;

        // int countA=0,countB=0;

        // while(d1!=NULL || d2!=NULL)
        // {
        //     if(d1!=NULL)
        //     {
        //         countA++;
        //         d1=d1->next;
        //     }
        //     if(d2!=NULL)
        //     {
        //         countB++;
        //         d2=d2->next;
        //     }
        // }

        // int diff=abs(countA-countB);
        // d1=headA;
        // d2=headB;

        // if(countA>countB)
        // {
        //     while(diff!=0)
        //     {
        //         d1=d1->next;
        //         diff--;
        //     }
        // }
        // else
        // {
        //     while(diff!=0)
        //     {
        //         d2=d2->next;
        //         diff--;
        //     }
        // }

        // while(d1!=NULL && d2!=NULL)
        // {
        //     if(d1==d2) return d1;
        //     else 
        //     {
        //         d1=d1->next;
        //         d2=d2->next;
        //     }
        // }
        // return d1;

        // COMPACT CODE FOR OPTIMAL APPROACH
        if(headA==NULL || headB==NULL) return NULL;
        ListNode* d1=headA;
        ListNode* d2=headB;

        while(d1!=d2)
        {
            if(d1==d2) return d1;
            if(d1==NULL)
            {
                d1=headB;
            }
            else d1=d1->next;
            if(d2==NULL)
            {
                d2=headA;
            }
            else
            {
                d2=d2->next;
            }
        }
        return d1;
    }
};