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


pair<bool,int> SumTree(Node* root)
{
    if(root==NULL)
    {
        pair<bool,int> p;
        p.first=true;
        p.second=0;
        return p;
    }

    if(root->left==NULL && root->right==NULL)
    {
        pair<bool,int> p;
        p.first=true;
        p.second=root->data;
        return p;
    }

    pair<bool,int> leftAns = SumTree(root->left);
    pair<bool,int> rightAns = SumTree(root->right);

    bool condn = root->data==leftAns.second+rightAns.second;

    bool leftSum=leftAns.first;
    bool rightSum=rightAns.first;

    pair<bool,int> ans;

    if(leftSum && rightSum && condn)
    {
        ans.first=true;
        ans.second=2*root->data;
    }
    else{
        ans.first=false;
    }
    return ans;

    
}




int main()
{
    Node* root = TakeInputlevelwise();

    cout<<SumTree(root).first<<endl;

   
    return 0;
}