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

class QueueLinked
{
public:
    Node *head;
    Node *tail;
    int size;

    QueueLinked()
    {
        head = tail = NULL;
        size=0;
    }

    int length()
    {
        return size;
    }

    bool isEmpty()
    {
        if(size==0)
        {
            return true;
        }
        else{
            return false;
        }
    }

    void push(int element)
    {
       Node* newNode = new Node(element);

       if(head==NULL)
       {
           head=newNode;
           tail=newNode;
       }
       else{
           tail->next=newNode;
           tail=newNode;
       }
       size++;
    }

    int pop()
    {
       if(isEmpty())
       {
           return -1;
       }

       int ans=head->data;
        Node *temp=head;
        head=head->next;
        delete temp;
        size--;
        return ans;
    }

    int front() {
        // Implement the front() function
        if(isEmpty()){
            return -1;
        }
        return head->data;
    }
};

int main()
{
    QueueLinked qe;

    qe.push(1);
    qe.push(2);
    qe.push(3);
    qe.push(4);
    cout << qe.pop() << endl;
    cout << qe.pop() << endl;
    cout << qe.pop() << endl;
    cout << qe.pop() << endl;
    cout << qe.pop() << endl;

    return 0;
}