// coding ninjas
/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/

int lengthOfLoop(Node *head) {
    // Write your code here
    Node* fast=head;
    Node* slow=head;
    int len=0;
    while(fast != NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)break;
    }
    if(fast==NULL || fast->next==NULL) return 0;
    slow=slow->next;
    while(slow!=fast)
    {
        len++;
        slow=slow->next;
    }
    return len+1;

}
