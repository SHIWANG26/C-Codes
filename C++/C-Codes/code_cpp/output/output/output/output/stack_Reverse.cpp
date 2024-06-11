
#include<stack>
#include <iostream>
using namespace std;

void insertAtBottom(stack<int>& s, int target){
    if (s.empty())
    {
        s.push(target);
        return;
    }
    int topElement = s.top();
    s.pop();
    insertAtBottom(s,target);
    s.push(topElement);
}

int main()
{
stack<int> s;
s.push(2);
s.push(3);
s.push(4);
s.push(5);
s.push(6);
s.push(7);
int target = s.top();
s.pop();
insertAtBottom(s,target);
while (!s.empty())
{
    cout<<s.top();
    s.pop();
}

return 0;
}
