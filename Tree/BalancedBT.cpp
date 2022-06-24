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


int heightdiff(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int lh = heightdiff(root->left);
    if(lh==-1)return -1;
    int rh = heightdiff(root->right);
    if(rh==-1)return -1;

    if(abs(lh-rh)>1)return -1;
    return 1+ max(lh,rh);
}


bool isBalanced(Node* root)
{
    if(heightdiff(root)!=-1)
    {
        return true;
    }
    else{
        return false;
    }
}


int main()
{
    Node* root = TakeInputlevelwise();

   if(isBalanced)
   {
       cout<<"Balanced!"<<endl;
   }
   else{
       cout<<"Not Balanced!"<<endl;
   }

    return 0;
}