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

int length(Node* head)
{
    int count=0;
    Node* temp = head;

    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}


int main(int argc, char const *argv[])
{
    Node*head=takeInput();

    int l=length(head);

    cout<<"Length:"<<" "<<l<<endl;
    
    return 0;
}
