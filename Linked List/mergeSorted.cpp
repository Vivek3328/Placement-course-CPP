#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

Node* takeInput()
{
    int data;
    cout<<"Enter Data:"<<" ";
    cin>>data;

    Node* head=NULL;
    Node* tail=NULL;

    while (data!=-1)
    {
        Node* newNode=new Node(data);

        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=tail->next;
        }
        cout<<"Enter Data:"<<" ";
        cin>>data;
    }
    return head;
}

void print(Node* head)
{
    if(head==NULL)
    {
        return;
    }

    Node* temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

Node* merged(Node* first, Node* second)
{
    Node*p1=first;
    Node*p2=second;
    Node* dummy = new Node(0);
    Node*p3=dummy;

    while (p1!=NULL && p2!=NULL )
    {
        if(p1->data<p2->data)
        {
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }

    if(p1!=NULL)
    {
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }

     if(p2!=NULL)
    {
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }

    return dummy->next;
    
}

int main(int argc, char const *argv[])
{
    Node*first=takeInput();
    Node*second=takeInput();
    
    Node* merge = merged(first,second);

    print(merge);
    
    return 0;
}
