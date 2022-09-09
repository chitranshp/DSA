//https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1

#include<bits/stdc++.h>

using namespace std;

class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();

};

int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        StackQueue *sq = new StackQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }


}


void StackQueue :: push(int x)
{
    s1.push(x);
}

int StackQueue :: pop()
{   
    int popped_ele = 0;
    if(s2.empty())
    {
        if(s1.empty())
            return -1;
        
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        popped_ele = s2.top();
        s2.pop();
    }
    else
    {
        popped_ele = s2.top();
        s2.pop();
    }
    return popped_ele;
}
