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



bool isIdentical(Node* first, Node* second)
{
    if(first==NULL && second==NULL)
    {
        return true;
    }

    if(first!=NULL && second==NULL)
    {
        return false;
    }

    if(first==NULL && second!=NULL)
    {
        return false;
    }

    bool leftAns = isIdentical(first->left,second->left);
    bool rightAns = isIdentical(first->right,second->right);

    bool value = first->data==second->data;

    if(leftAns && rightAns && value)
    {
        return true;
    }
    else{
        return false;
    }
}




int main()
{
    Node* r1 = TakeInputlevelwise();
    Node* r2 = TakeInputlevelwise();

    if(isIdentical(r1,r2))
    {
        cout<<"Tree is Identical!"<<endl;
    }
    else{
        cout<<"Tree is Not Identical!"<<endl;
    }
   

    return 0;
}