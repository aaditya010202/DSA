// GFG
void reverse(stack<int> &stack,int x)
{
    if(stack.size()==0)
    {
        stack.push(x);
    }
    else
    {
        int top=stack.top();
        stack.pop();
        reverse(stack,x);
        stack.push(top);
    }

}
void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.size()>0)
    {
        int top=stack.top();
        stack.pop();
        reverseStack(stack);
        reverse(stack,top);
    }
}