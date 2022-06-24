#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Stack
{
public:
    Node *head;
    int size;

    Stack()
    {
        head = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        if (size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int element)
    {

        Node *temp = new Node(element);
        temp->next = head;
        head = temp;
        size++;
    }

    int pop()
    {
        if (isEmpty())
        {
            return -1;
        }
        int ans = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }

    int top()
    {
        if(isEmpty())
        {
            return -1;
        }
        return head->data;
    }
};

int main()
{
    Stack st;

    st.push(2);
    cout<<st.top()<<endl;



    return 0;
}