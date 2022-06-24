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


// Recurive Method
void postorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data <<" ";
}


//Iterative Method using Two Stack
void postorderIterative(Node* root)
{
    stack<Node*> s1;
    stack<Node*> s2;

    s1.push(root);

    while(!s1.empty())
    {
        root=s1.top();
        s1.pop();
        s2.push(root);

        if(root->left!=NULL)
        {
            s1.push(root->left);

        }

        if(root->right!=NULL)
        {
            s1.push(root->right);
        }
    }

    while(!s2.empty())
    {
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}


int main()
{
    Node* root = TakeInputlevelwise();

    postorder(root);
    cout<<endl;

    cout<<"Iterative: ";
    postorderIterative(root);

    return 0;
}