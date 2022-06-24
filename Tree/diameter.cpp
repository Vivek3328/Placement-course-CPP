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


pair<int,int> diameter(Node* root)
{
    if(root==NULL)
    {
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }

    pair<int,int> leftAns = diameter(root->left);
    pair<int,int> rightAns = diameter(root->right);

    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1+max(lh,rh);
    int diameters = max(lh+rh , max(ld,rd));

    pair<int,int> ans;
    ans.first = height;
    ans.second = diameters;
    return ans;
}





int main()
{
    Node* root = TakeInputlevelwise();

   cout<<"Diameter:"<<" "<<diameter(root).second<<endl;
   cout<<"Height:"<<" "<<diameter(root).first<<endl;

    return 0;
}