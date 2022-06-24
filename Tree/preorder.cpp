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


// Recursive Method
void preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data <<" ";
    preorder(root->left);
    preorder(root->right);
}


// Iterative Method
void preorderIterative(Node* root)
{
    stack<Node*> st;
    st.push(root);


    while(!st.empty())
    {
        root = st.top();
        st.pop();

        cout<<root->data<<" ";

        if(root->right!=NULL)
        {
            st.push(root->right);
        }

        if(root->left!=NULL)
        {
            st.push(root->left);
        }

    }
}


int main()
{
    Node* root = TakeInputlevelwise();

    preorder(root);
    cout<<"Iterative:"<<" ";
    preorderIterative(root);

    return 0;
}