// coding ninjas
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head){
    // Write your code here.
    if(head==NULL || head->next==NULL) return head;
    vector<int> v;
    Node* temp=head;
    while(temp!=NULL)
    {
        v.push_back(temp->data);
        temp=temp->next;
    }

    sort(v.begin(),v.end());

    temp=head;
    for(int i=0;i<v.size();i++)
    {
        temp->data=v[i];
        temp=temp->next;
    }
    return head;
}