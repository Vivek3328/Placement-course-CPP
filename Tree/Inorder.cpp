#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node *TakeInputlevelwise()
{
    cout << "Enter data: "
         << " ";
    int rootData;
    cin >> rootData;

    if (rootData == -1)
    {
        return NULL;
    }

    Node *root = new Node(rootData);

    queue<Node *> q;
    q.push(root);

    while (q.size() != 0)
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter Left Child :" << temp->data << endl;
        int leftdata;
        cin >> leftdata;

        if (leftdata != -1)
        {
            Node *child = new Node(leftdata);
            temp->left = child;
            q.push(child);
        }

        cout << "Enter right Child: " << temp->data << endl;
        int rightdata;
        cin >> rightdata;

        if (rightdata != -1)
        {
            Node *child = new Node(rightdata);
            temp->right = child;
            q.push(child);
        }
    }
    return root;
}


// Recursive Method;
void Inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    Inorder(root->left);
    cout<<root->data <<" ";
    Inorder(root->right);
    
}


// Iterative method
void InorderIterative(Node* root)
{
    stack<Node*> s;

    Node* temp = root;

    while(true)
    {
        if(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        else{
            if(s.empty()==true)
            {
                break;
            }
            temp=s.top();
            s.pop();
            cout<<temp->data<<" ";
            temp=temp->right;
        }
    }
}


int main()
{
    Node* root = TakeInputlevelwise();

    Inorder(root);
   cout<<endl;
   cout<<"Iterative:";
   InorderIterative(root);

    return 0;
}