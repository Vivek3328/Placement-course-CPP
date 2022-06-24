#include <bits/stdc++.h>
using namespace std;

class QueueArray
{
public:
    int *arr;
    int front;
    int rear;
    int size;

    QueueArray(int data)
    {
        size = data;
        rear = front = 0;
        arr = new int[data];
    }

    void push(int element)
    {
        if (size == rear)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[rear] = element;
            rear++;
        }
    }

    int pop()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int peek()
    {
        if(front==rear)
        {
            return -1;
        }
        else{
            return arr[front];
        }
    }

    bool isEmpty()
    {
        if(front==rear)
        {
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{
    QueueArray qu(5);

    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    
   cout<<qu.pop()<<endl;
   cout<<qu.pop()<<endl;
   cout<<qu.pop()<<endl;
   cout<<qu.pop()<<endl;

   if(qu.isEmpty())
   {
       cout<<"Queue is Empty"<<endl;
   }
   else{
       cout<<"Queue is not Empty"<<endl;
   }

    return 0;
}